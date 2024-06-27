#include "CppUnitTest.h"

#include "MaClasse.h"
#include "BlackJackMains.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BlackjackLibTests
{
	TEST_CLASS(MaClasseTests)
	{
	public:
		
		TEST_METHOD(ComparerMains_MainJouerPlusMainMaisonMoins21_1)
		{
			// Arranger

			BlackJackMains mains;
			mains.PourTesterLesMains(2, 8);
			mains.PourTesterLesMains(2, 10);
			mains.PourTesterLesMains(2, 3);
			// Agir
			int resultatAttendue  = 1;
			int resultat = mains.ComparerMains();
			
			// Auditer
			Assert::AreEqual(resultat, resultatAttendue);
		}
		TEST_METHOD(ComparerMains_MainJouerEgalMainMaisonMoins21_0)
		{
			// Arranger
			BlackJackMains mains;
			mains.PourTesterLesMains(2, 2);
			mains.PourTesterLesMains(2, 2);
			mains.PourTesterLesMains(2, 2);
			// Agir
			int resultatAttendue = 0;
			int resultat = mains.ComparerMains();
			// Auditer
			Assert::AreEqual(resultat, resultatAttendue);
		}
		TEST_METHOD(ComparerMains_MainJouermoinsMainMaisonMoins_moins1)
		{
			// Arranger
			BlackJackMains mains;
			mains.PourTesterLesMains(10, 2);
			mains.PourTesterLesMains(2, 2);
			mains.PourTesterLesMains(2, 2);
			// Agir
			int resultatAttendue = -1;
			int resultat = mains.ComparerMains();
			// Auditer
			Assert::AreEqual(resultat, resultatAttendue);
		}
		TEST_METHOD(ComparerMains_MainJouerplus21_moins1)
		{
			// Arranger
			BlackJackMains mains;
			mains.PourTesterLesMains(10, 10);
			mains.PourTesterLesMains(2, 10);
			mains.PourTesterLesMains(2, 2);
			// Agir
			int resultatAttendue = -1;
			int resultat = mains.ComparerMains();
			// Auditer
			Assert::AreEqual(resultat, resultatAttendue);
		}
		TEST_METHOD(ComparerMains_MainJouerEgalMais21_moins1)
		{
			// Arranger
			BlackJackMains mains;
			mains.PourTesterLesMains(9, 9);
			mains.PourTesterLesMains(10, 10);
			mains.PourTesterLesMains(2, 2);
			// Agir
			int resultatAttendue = -1;
			int resultat = mains.ComparerMains();
			// Auditer
			Assert::AreEqual(resultat, resultatAttendue);
		}
		TEST_METHOD(ComparerMains_MainJouerPlus21MaisAsTirerAudernierMainMaisonmoins_1)
		{
			// Arranger
			BlackJackMains mains;
			mains.PourTesterLesMains(9, 8);
			mains.PourTesterLesMains(3, 10);
			mains.PourTesterLesMains(2, 2);
			mains.PourTesterAsTirer();
			// Agir
			int resultatAttendue = 1;
			int resultat = mains.ComparerMains();
			// Auditer
			Assert::AreEqual(resultat, resultatAttendue);
		}
	};

}
