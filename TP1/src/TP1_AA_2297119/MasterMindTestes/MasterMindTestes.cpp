#include "pch.h"
#include "CppUnitTest.h"
#include "../MMStatique/Liste.h"
#include "../MMStatique/Ronde.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MasterMindTestes
{
	TEST_CLASS(MasterMindTestes)
	{
	public:

		TEST_METHOD(EvaluerProposition_RienSeTrouve_ZeroAttendue)
		{
			Liste<char> prop;
			Liste<char> code;
			Liste<int> index;
			prop.RemplirParChaine("XXXXX");
			code.RemplirParChaine("VVBBB");
			Ronde ronde(prop,code,index,5);
			int resultatAttendue = 0;

			ronde.EvaluerProposition();
			int resultat = ronde.TrouveBonnePlacee() + ronde.TrouveMalPlacee();
			
			Assert::AreEqual(resultatAttendue,resultat);
		}
		TEST_METHOD(EvaluerProposition_BienPlaceeSeulement_MP0_BPresualtat)
		{
			Liste<char> prop;
			Liste<char> code;
			Liste<int> index;
			prop.RemplirParChaine("VVXXX");
			code.RemplirParChaine("VVBBB");
			Ronde ronde(prop, code, index, 5);
			int resultatAttendue1 = 2;
			int resultatAttendue2 = 0;

			ronde.EvaluerProposition();
			int resultat1 = ronde.TrouveBonnePlacee();
			int resultat2 = ronde.TrouveMalPlacee();

			Assert::AreEqual(resultatAttendue1, resultat1);
			Assert::AreEqual(resultatAttendue2, resultat2);
		}
		TEST_METHOD(EvaluerProposition_MalPlaceeSeulement_MPresultat_BP0)
		{
			Liste<char> prop;
			Liste<char> code;
			Liste<int> index;
			prop.RemplirParChaine("VVXXX");
			code.RemplirParChaine("BBBVV");
			Ronde ronde(prop, code, index, 5);
			int resultatAttendue1 = 0;
			int resultatAttendue2 = 2;

			ronde.EvaluerProposition();
			int resultat1 = ronde.TrouveBonnePlacee();
			int resultat2 = ronde.TrouveMalPlacee();

			Assert::AreEqual(resultatAttendue1, resultat1);
			Assert::AreEqual(resultatAttendue2, resultat2);
		}
		TEST_METHOD(EvaluerProposition_MalPlaceeEtBienPlacee_MPegalBP)
		{
			Liste<char> prop;
			Liste<char> code;
			Liste<int> index;
			prop.RemplirParChaine("BBXBB");
			code.RemplirParChaine("BBJVV");
			Ronde ronde(prop, code, index, 5);
			int resultatAttendue1 = 2;
			int resultatAttendue2 = 2;

			ronde.EvaluerProposition();
			int resultat1 = ronde.TrouveBonnePlacee();
			int resultat2 = ronde.TrouveMalPlacee();

			Assert::AreEqual(resultatAttendue1, resultat1);
			Assert::AreEqual(resultatAttendue2, resultat2);
		}
		TEST_METHOD(EvaluerProposition_Decrypter_BienPlaceeEgalPLions)
		{
			Liste<char> prop;
			Liste<char> code;
			Liste<int> index;
			prop.RemplirParChaine("BBJVV");
			code.RemplirParChaine("BBJVV");
			Ronde ronde(prop, code, index, 5);
			int resultatAttendue = 5;

			ronde.EvaluerProposition();
			int resulat = ronde.TrouveBonnePlacee();

			Assert::AreEqual(resultatAttendue,resulat);
		}
	};
}
