#ifndef C_SINGLETON_H
#define C_SINGLETON_H

#include <cstdlib>

namespace mqclient
{
	/*!
	 * \brief Classe de base de tous les singletons.
	 */
	template <class T>
	class CSingleton
	{
	public:
		/*!
		 * \brief Renvoi l'instance de la classe.
		 *
		 * \return L'instance unique de cette classe.
		 */
		static T& GetInstance();

		/*!
		 * \brief D�truit l'instance de la classe.
		 */
		static void Destroy();

	protected:

		/*!
		 * \brief Constructeur.
		 */
		CSingleton();

		/*!
		 * \brief Destructeur.
		 */
		~CSingleton();

	private:
		/*!
		 * \brief Constructeur par recopie.
		 *
		 * \param [in] roSingleton Le singleton � partir duquel effectuer la copie.
		 */
		CSingleton(CSingleton& roSingleton);

		/*!
		 * \brief Op�rateur binaire = avec un autre singleton.
		 *
		 * \param [in] roSingleton Le singleton � affecter � celui-ci.
		 */
		void operator =(CSingleton& roSingleton); /*!< Op�rateur binaire = */

		static T* ms_ptInstance; /*!< L'instance (unique) de cette classe. */
	};

	/*!
	 * \brief Donne l'acc�s au singleton � la construction du type encapsul�.
	 */
#define SINGLETON_DECLARE(Class) \
			public : \
			friend class CSingleton<Class>; \
				static Class& GetInstance(); \
			private:

	 /*!
	  * \brief Initialise un singleton.
	  */
#define SINGLETON_IMPL(Class) \
		template <> Class* CSingleton<Class>::ms_ptInstance = 0; \
			Class& Class::GetInstance() \
			{ \
			return CSingleton<Class>::GetInstance(); \
			} /*!< Initialise le pointeur static d'un singleton. */
}

#include "CSingleton.inl"

#endif // C_SINGLETON_H