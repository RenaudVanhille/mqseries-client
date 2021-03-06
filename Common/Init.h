#ifndef __INIT_H__
#define __INIT_H__

#include "../Promise/CPromiseData.h"
#include "../Sub/CSub.h"
#include "../Pub/CPub.h"

using v8::FunctionCallbackInfo;
using v8::String;
using v8::Value;

#include <chrono>
#include <thread>

namespace mqclient
{
	struct SInit
	{
		struct SArgs
		{
			SArgs(const char* strQM, const char* strTopic)
				:	m_strQM(strQM),
					m_strTopic(strTopic)
			{

			}

			std::string m_strQM;
			std::string m_strTopic;
		};

		static void* BuildArgs(const FunctionCallbackInfo<Value>& args)
		{
			String::Utf8Value arg1(args[0]);
			String::Utf8Value arg2(args[1]);

			return new SArgs(*arg1, *arg2);
		}

		static TArgsDef Def() {
			return std::vector<std::string>({ "string", "string" });
		}

		static void Run(CPromiseData* pData)
		{
			const SArgs* pArgs = static_cast<const SArgs*>(pData->GetArgs());
			pData->Set("", PUB.Init(pArgs->m_strQM, pArgs->m_strTopic));
		}
	};
}

#endif // __INIT_H__