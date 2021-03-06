#define _CRT_SECURE_NO_WARNINGS
#include"DX9Lib.h"
#include"WinMain.h"
#include"ControlCharaChoice.h"
#include"ControlHome.h"

void ControlHome(SCENE* scene, WordData* pMagicKnightWordDatas, Deck* pMagicKnightDecks,
	WordData* pWeaponMAsterWordDatas, Deck* pWeaponMasterDecks,
	CustomVertex* pDeckAlterPortal, CustomVertex* pModifyWordPortal, CustomVertex* pMainGamePortal,
	CustomVertex* pCharaChoicePortal, TEXTUREID* mKWordTex, TEXTUREID* wMWordTex, PLAYERTYPE* playerType,
	bool* initializedTex)
{
	static int frameCount = -1;
	
	if (!(*initializedTex))
	{
		LoadWordDatas(pWeaponMAsterWordDatas, "Files/WordStates/WeaponMasterWordStates.csv", WEAPON_MASTER_WORD_MAX);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck1.csv", 0);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck2.csv", 1);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck3.csv", 2);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck4.csv", 3);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck5.csv", 4);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck6.csv", 5);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck7.csv", 6);
		LoadDeck(pWeaponMAsterWordDatas, pWeaponMasterDecks, "Files/WMDeck/WMDeck8.csv", 7);
		LordTextureWeaponMaster(wMWordTex);
		LoadWordDatas(pMagicKnightWordDatas, "Files/WordStates/MagicKnightWordStates.csv", MAGIC_KNIGHT_WORD_MAX);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck1.csv", 0);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck2.csv", 1);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck3.csv", 2);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck4.csv", 3);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck5.csv", 4);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck6.csv", 5);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck7.csv", 6);
		LoadDeck(pMagicKnightWordDatas, pMagicKnightDecks, "Files/Deck/MKDeck8.csv", 7);

		RoadTexture("Texture/MKWord/VOID_WORD.png", &mKWordTex[VOID_WORD]);

		FILE* pWordTexPathsFile;

		pWordTexPathsFile = fopen("Files/TexturePaths/MKWordTexPaths.csv", "r");

		for (int word = VOID_WORD + 1; word < MAGIC_KNIGHT_WORD_MAX; ++word)
		{
			char mkWordPath[60];

			fscanf(pWordTexPathsFile, "%s,", mkWordPath);
			RoadTexture(mkWordPath, &mKWordTex[word]);
		}

		fclose(pWordTexPathsFile);

		*initializedTex = true;
	}

	//マウスカーソル
	CustomVertex mouseCursorCollisionVertex[RECT_VERTEX_NUM];

	const float MOUSE_CURSOR_SCALE = 0.5f;
	CustomImageVerticies(mouseCursorCollisionVertex, (float)g_mouseState.absolutePos.x, (float)g_mouseState.absolutePos.y, MOUSE_CURSOR_SCALE, MOUSE_CURSOR_SCALE);

	const float MAIN_GAME_PORTAL_SCALE = DISPLAY_WIDTH / 10.f;
	CustomImageVerticies(pMainGamePortal, DISPLAY_WIDTH*0.625f, DISPLAY_HEIGHT*0.625f, MAIN_GAME_PORTAL_SCALE, MAIN_GAME_PORTAL_SCALE, 0xe5f0f0f0);

	if (g_mouseState.mousePush[LEFT_CLICK])
	{
		if (RectToRectCollisionCheak(mouseCursorCollisionVertex, pMainGamePortal))
		{
			*scene = SELECT_STAGE_SCENE;
			isSuccess = soundsManager.Stop(_T("Homebgm"));
			isSuccess = soundsManager.Start(_T("Alterbgm"));
		}
	}

	const float MID_PORTAL_SCALE_X = (float)(MAIN_GAME_PORTAL_SCALE * 0.8);
	const float MID_PORTAL_SCALE_Y = (float)(MAIN_GAME_PORTAL_SCALE * 0.4);

	CustomImageVerticies(pDeckAlterPortal, 
		(float)(DISPLAY_WIDTH*0.625f + MAIN_GAME_PORTAL_SCALE * 2), (float)(DISPLAY_HEIGHT*0.625f - MAIN_GAME_PORTAL_SCALE * 0.6),
		(float)MID_PORTAL_SCALE_X, (float)MID_PORTAL_SCALE_Y);

	if (g_mouseState.mousePush[LEFT_CLICK])
	{
		if (RectToRectCollisionCheak(mouseCursorCollisionVertex, pDeckAlterPortal))
		{
			*scene = CHOSE_DECK_TO_ALTER_SCENE;
			isSuccess = soundsManager.Stop(_T("Homebgm"));
			isSuccess = soundsManager.Start(_T("Alterbgm"));
		}
	}

	/*CustomImageVerticies(pModifyWordPortal,
		(float)(DISPLAY_WIDTH*0.625f + MAIN_GAME_PORTAL_SCALE * 2), (float)(DISPLAY_HEIGHT*0.625f + MAIN_GAME_PORTAL_SCALE * 0.6),
		(float)MID_PORTAL_SCALE_X, (float)MID_PORTAL_SCALE_Y);

	if (g_mouseState.mousePush[LEFT_CLICK])
	{
		if (RectToRectCollisionCheak(mouseCursorCollisionVertex, pModifyWordPortal))
		{
			*scene = MODIFY_WORD_SCENE;
			isSuccess = soundsManager.Stop(_T("bgm"));
		}
	}*/

	CustomImageVerticies(pCharaChoicePortal, DISPLAY_HEIGHT*0.08f, DISPLAY_HEIGHT*0.04f, DISPLAY_HEIGHT*0.08f, DISPLAY_HEIGHT*0.04f,0xe6ffeeee);

	if (g_mouseState.mousePush[LEFT_CLICK])
	{
		if (RectToRectCollisionCheak(mouseCursorCollisionVertex, pCharaChoicePortal))
		{
			*scene = CHARA_CHOICE_SCENE;


			/**initializedTex = false;

			for (int word = 0; word < WEAPON_MASTER_WORD_MAX; ++word)
			{
				SAFE_RELEASE(wMWordTex[word]);
			}

			for (int word = 0; word < MAGIC_KNIGHT_WORD_MAX; ++word)
			{
				SAFE_RELEASE(mKWordTex[word]);
			}*/
		}
	}

	return;
}

void LoadWordDatas(WordData* pMagicKnightWordDatas,const char *pFilePath,int wordDataMax)
{
	FILE* pWordStatesFile;

	fopen_s(&pWordStatesFile, pFilePath, "r");

	memset(pMagicKnightWordDatas, 0, sizeof(WordData)*wordDataMax);

	//魔法剣士のワードデーターを入れていく
	for (int wordsNum = VOID_WORD + 1; wordsNum < wordDataMax; ++wordsNum)
	{
		//外部ファイルの属性を数字に直したいので一度文字列で保管する
		const int ELEMENTAL_WORDS_MAX = 10;
		char elemental[ELEMENTAL_WORDS_MAX];
		memset(elemental, 0, sizeof(char)*ELEMENTAL_WORDS_MAX);

		const int ATTACK_WORDS_MAX = 10;
		char attack[ATTACK_WORDS_MAX];
		memset(attack, 0, sizeof(char)*ATTACK_WORDS_MAX);

		//外部ファイルからの入力
		fscanf(pWordStatesFile, "%[^,],%[^,],%[^,],%*x,%*d,%*d,%*d,%*d,%d", pMagicKnightWordDatas[wordsNum].m_word, elemental, attack, 
			&pMagicKnightWordDatas[wordsNum].m_have);

		//￥ｎの対処
		if (wordsNum > VOID_WORD)
		{
			fscanf(pWordStatesFile, "%*c");
		}

		//特殊属性の数だけ回す
		for (int elementalNum = 0; elementalNum < ELEMENT_ATTRIBUTES_MAX; ++elementalNum)
		{
			//属性が決まったかどうか
			bool wasInputElemental = false;

			//属性を文字列で保管していたので数字に変換する
			switch (elementalNum)
			{
			case FIRE_ELEMENT:

				if (!strcmp("fi", elemental))
				{
					pMagicKnightWordDatas[wordsNum].m_element = FIRE_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case WATER_ELEMENT:

				if (!strcmp("wa", elemental))
				{
					pMagicKnightWordDatas[wordsNum].m_element = WATER_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case WIND_ELEMENT:

				if (!strcmp("wi", elemental))
				{
					pMagicKnightWordDatas[wordsNum].m_element = WIND_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case SHINING_ELEMENT:

				if (!strcmp("sh", elemental))
				{
					pMagicKnightWordDatas[wordsNum].m_element = SHINING_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case DARKNESS_ELEMENT:

				if (!strcmp("da", elemental))
				{
					pMagicKnightWordDatas[wordsNum].m_element = DARKNESS_ELEMENT;

					wasInputElemental = true;
				}

			case VOID_ELEMENT:

				if (!strcmp("0", elemental))
				{
					pMagicKnightWordDatas[wordsNum].m_element = VOID_ELEMENT;

					wasInputElemental = true;
				}

				break;
			}

			if (wasInputElemental)
			{
				break;
			}
		}

		//物理属性の数だけ回す
		for (int attackNum = 0; attackNum < ATTACK_ATTRIBUTES_MAX; ++attackNum)
		{
			bool wasInputAttack = 0;

			switch (attackNum)
			{
			case SLASH_ATTACK:

				if (!strcmp("sl", attack))
				{
					pMagicKnightWordDatas[wordsNum].m_attack = SLASH_ATTACK;

					wasInputAttack = true;
				}

				break;

			case SMASH_ATTACK:

				if (!strcmp("sm", attack))
				{
					pMagicKnightWordDatas[wordsNum].m_attack = SMASH_ATTACK;

					wasInputAttack = true;
				}

				break;

			case PENETRATION_ATTACK:

				if (!strcmp("pe", attack))
				{
					pMagicKnightWordDatas[wordsNum].m_attack = PENETRATION_ATTACK;

					wasInputAttack = true;
				}

				break;

			case VOID_ATTACK:

				if (!strcmp("0", attack))
				{
					pMagicKnightWordDatas[wordsNum].m_attack = VOID_ATTACK;
				}

				break;
			}

			if (wasInputAttack)
			{
				break;
			}
		}
	}

	fclose(pWordStatesFile);

	return;
}

void LoadDeck(WordData* pMagicKnightWordDatas, Deck* pMagicKnightDecks, const char* deckFilePath,int deckNum)
{
	FILE* pDeckFile;

	pDeckFile = fopen(deckFilePath, "r");

	memset(&pMagicKnightDecks[deckNum], 0, sizeof(Deck));

	fscanf(pDeckFile, "%*[^,]");

	for (int deckWordNum = 0; deckWordNum < DECK_WORD_MAX; ++deckWordNum)
	{
		fseek(pDeckFile, 1, SEEK_CUR);
		fscanf(pDeckFile,"%d", &pMagicKnightDecks[deckNum].m_wordId[deckWordNum]);

		int wordId = pMagicKnightDecks[deckNum].m_wordId[deckWordNum];

		if (!wordId)
		{
			break;
		}

		pMagicKnightDecks[deckNum].m_wordNum += 1;
	}

	fclose(pDeckFile);

	return;
}

void LordTextureWeaponMaster(TEXTUREID* pWmFontIds)
{
	static int isFirstFrame = INIT_FRAME;

	if (isFirstFrame == INIT_FRAME)
	{
		RoadTexture("Texture/WeaponMasterWord/VoidWord.png", &pWmFontIds[VOID_WORD]);
		RoadTexture("Texture/WeaponMasterWord/火.png", &pWmFontIds[火]);
		RoadTexture("Texture/WeaponMasterWord/熱.png", &pWmFontIds[熱]);
		RoadTexture("Texture/WeaponMasterWord/燃.png", &pWmFontIds[燃]);
		RoadTexture("Texture/WeaponMasterWord/灯.png", &pWmFontIds[灯]);
		RoadTexture("Texture/WeaponMasterWord/炉.png", &pWmFontIds[炉]);
		RoadTexture("Texture/WeaponMasterWord/紅.png", &pWmFontIds[紅]);
		RoadTexture("Texture/WeaponMasterWord/赤.png", &pWmFontIds[赤]);
		RoadTexture("Texture/WeaponMasterWord/水.png", &pWmFontIds[水]);
		RoadTexture("Texture/WeaponMasterWord/青.png", &pWmFontIds[青]);
		RoadTexture("Texture/WeaponMasterWord/雨.png", &pWmFontIds[雨]);
		RoadTexture("Texture/WeaponMasterWord/氷.png", &pWmFontIds[氷]);
		RoadTexture("Texture/WeaponMasterWord/雪.png", &pWmFontIds[雪]);
		RoadTexture("Texture/WeaponMasterWord/冷.png", &pWmFontIds[冷]);
		RoadTexture("Texture/WeaponMasterWord/緑.png", &pWmFontIds[緑]);
		RoadTexture("Texture/WeaponMasterWord/光.png", &pWmFontIds[光]);
		RoadTexture("Texture/WeaponMasterWord/明.png", &pWmFontIds[明]);
		RoadTexture("Texture/WeaponMasterWord/暗.png", &pWmFontIds[暗]);
		RoadTexture("Texture/WeaponMasterWord/白.png", &pWmFontIds[白]);
		RoadTexture("Texture/WeaponMasterWord/黒.png", &pWmFontIds[黒]);
		RoadTexture("Texture/WeaponMasterWord/悪.png", &pWmFontIds[悪]);
		RoadTexture("Texture/WeaponMasterWord/刃.png", &pWmFontIds[刃]);
		RoadTexture("Texture/WeaponMasterWord/刀.png", &pWmFontIds[刀]);
		RoadTexture("Texture/WeaponMasterWord/弾.png", &pWmFontIds[弾]);
		RoadTexture("Texture/WeaponMasterWord/切.png", &pWmFontIds[切]);
		RoadTexture("Texture/WeaponMasterWord/打.png", &pWmFontIds[打]);
		RoadTexture("Texture/WeaponMasterWord/拳.png", &pWmFontIds[拳]);
		RoadTexture("Texture/WeaponMasterWord/叩.png", &pWmFontIds[叩]);
		RoadTexture("Texture/WeaponMasterWord/突.png", &pWmFontIds[突]);
		RoadTexture("Texture/WeaponMasterWord/矢.png", &pWmFontIds[矢]);
		RoadTexture("Texture/WeaponMasterWord/刺.png", &pWmFontIds[刺]);
		RoadTexture("Texture/WeaponMasterWord/爪.png", &pWmFontIds[爪]);
		RoadTexture("Texture/WeaponMasterWord/空.png", &pWmFontIds[空]);
		RoadTexture("Texture/WeaponMasterWord/亜.png", &pWmFontIds[亜]);
		RoadTexture("Texture/WeaponMasterWord/新.png", &pWmFontIds[新]);
		RoadTexture("Texture/WeaponMasterWord/源.png", &pWmFontIds[源]);
		RoadTexture("Texture/WeaponMasterWord/我.png", &pWmFontIds[我]);
		RoadTexture("Texture/WeaponMasterWord/扇.png", &pWmFontIds[扇]);
		RoadTexture("Texture/WeaponMasterWord/完.png", &pWmFontIds[完]);
		RoadTexture("Texture/WeaponMasterWord/全.png", &pWmFontIds[全]);
		RoadTexture("Texture/WeaponMasterWord/一.png", &pWmFontIds[一]);
		RoadTexture("Texture/WeaponMasterWord/千.png", &pWmFontIds[千]);
		RoadTexture("Texture/WeaponMasterWord/之.png", &pWmFontIds[之]);
		RoadTexture("Texture/WeaponMasterWord/気.png", &pWmFontIds[気]);
		RoadTexture("Texture/WeaponMasterWord/深.png", &pWmFontIds[深]);
		RoadTexture("Texture/WeaponMasterWord/速.png", &pWmFontIds[速]);
		RoadTexture("Texture/WeaponMasterWord/心.png", &pWmFontIds[心]);
		RoadTexture("Texture/WeaponMasterWord/紫.png", &pWmFontIds[紫]);
		RoadTexture("Texture/WeaponMasterWord/電.png", &pWmFontIds[電]);
		RoadTexture("Texture/WeaponMasterWord/弓.png", &pWmFontIds[弓]);
		RoadTexture("Texture/WeaponMasterWord/朽.png", &pWmFontIds[朽]);
		RoadTexture("Texture/WeaponMasterWord/究.png", &pWmFontIds[究]);
		RoadTexture("Texture/WeaponMasterWord/残.png", &pWmFontIds[残]);
		RoadTexture("Texture/WeaponMasterWord/型.png", &pWmFontIds[型]);
		RoadTexture("Texture/WeaponMasterWord/壱.png", &pWmFontIds[壱]);
		RoadTexture("Texture/WeaponMasterWord/弐.png", &pWmFontIds[弐]);
		RoadTexture("Texture/WeaponMasterWord/参.png", &pWmFontIds[参]);
		RoadTexture("Texture/WeaponMasterWord/肆.png", &pWmFontIds[肆]);
		RoadTexture("Texture/WeaponMasterWord/伍.png", &pWmFontIds[伍]);
		RoadTexture("Texture/WeaponMasterWord/陸.png", &pWmFontIds[陸]);
		RoadTexture("Texture/WeaponMasterWord/漆.png", &pWmFontIds[漆]);
		RoadTexture("Texture/WeaponMasterWord/撥.png", &pWmFontIds[撥]);
		RoadTexture("Texture/WeaponMasterWord/玖.png", &pWmFontIds[玖]);
		RoadTexture("Texture/WeaponMasterWord/拾.png", &pWmFontIds[拾]);
		RoadTexture("Texture/WeaponMasterWord/地.png", &pWmFontIds[地]);
		RoadTexture("Texture/WeaponMasterWord/飛.png", &pWmFontIds[飛]);
		RoadTexture("Texture/WeaponMasterWord/眼.png", &pWmFontIds[眼]);
		RoadTexture("Texture/WeaponMasterWord/士.png", &pWmFontIds[士]);
		RoadTexture("Texture/WeaponMasterWord/雅.png", &pWmFontIds[雅]);
		RoadTexture("Texture/WeaponMasterWord/陣.png", &pWmFontIds[陣]);
		RoadTexture("Texture/WeaponMasterWord/止.png", &pWmFontIds[止]);
		RoadTexture("Texture/WeaponMasterWord/花.png", &pWmFontIds[花]);
		RoadTexture("Texture/WeaponMasterWord/克.png", &pWmFontIds[克]);
		RoadTexture("Texture/WeaponMasterWord/環.png", &pWmFontIds[環]);
		RoadTexture("Texture/WeaponMasterWord/望.png", &pWmFontIds[望]);
		RoadTexture("Texture/WeaponMasterWord/叶.png", &pWmFontIds[叶]);
		RoadTexture("Texture/WeaponMasterWord/降.png", &pWmFontIds[降]);
		RoadTexture("Texture/WeaponMasterWord/浸.png", &pWmFontIds[浸]);
		RoadTexture("Texture/WeaponMasterWord/徹.png", &pWmFontIds[徹]);
		RoadTexture("Texture/WeaponMasterWord/透.png", &pWmFontIds[透]);
		RoadTexture("Texture/WeaponMasterWord/定.png", &pWmFontIds[定]);
		RoadTexture("Texture/WeaponMasterWord/反.png", &pWmFontIds[反]);
		RoadTexture("Texture/WeaponMasterWord/逆.png", &pWmFontIds[逆]);
		RoadTexture("Texture/WeaponMasterWord/即.png", &pWmFontIds[即]);
		RoadTexture("Texture/WeaponMasterWord/意.png", &pWmFontIds[意]);
		RoadTexture("Texture/WeaponMasterWord/古.png", &pWmFontIds[古]);
		RoadTexture("Texture/WeaponMasterWord/甚.png", &pWmFontIds[甚]);
		RoadTexture("Texture/WeaponMasterWord/迎.png", &pWmFontIds[迎]);
		RoadTexture("Texture/WeaponMasterWord/雲.png", &pWmFontIds[雲]);
		RoadTexture("Texture/WeaponMasterWord/那.png", &pWmFontIds[那]);
		RoadTexture("Texture/WeaponMasterWord/伐.png", &pWmFontIds[伐]);
		RoadTexture("Texture/WeaponMasterWord/掃.png", &pWmFontIds[掃]);
		RoadTexture("Texture/WeaponMasterWord/序.png", &pWmFontIds[序]);
		RoadTexture("Texture/WeaponMasterWord/除.png", &pWmFontIds[除]);
		RoadTexture("Texture/WeaponMasterWord/急.png", &pWmFontIds[急]);
		RoadTexture("Texture/WeaponMasterWord/悟.png", &pWmFontIds[悟]);
		RoadTexture("Texture/WeaponMasterWord/啓.png", &pWmFontIds[啓]);
		RoadTexture("Texture/WeaponMasterWord/彗.png", &pWmFontIds[彗]);
		RoadTexture("Texture/WeaponMasterWord/遺.png", &pWmFontIds[遺]);
		RoadTexture("Texture/WeaponMasterWord/転.png", &pWmFontIds[転]);
		RoadTexture("Texture/WeaponMasterWord/回.png", &pWmFontIds[回]);
		RoadTexture("Texture/WeaponMasterWord/智.png", &pWmFontIds[智]);
		RoadTexture("Texture/WeaponMasterWord/圧.png", &pWmFontIds[圧]);
		RoadTexture("Texture/WeaponMasterWord/敗.png", &pWmFontIds[敗]);
		RoadTexture("Texture/WeaponMasterWord/兎.png", &pWmFontIds[兎]);
		RoadTexture("Texture/WeaponMasterWord/ノ.png", &pWmFontIds[ノ]);
		RoadTexture("Texture/WeaponMasterWord/放.png", &pWmFontIds[放]);
		RoadTexture("Texture/WeaponMasterWord/離.png", &pWmFontIds[離]);
		RoadTexture("Texture/WeaponMasterWord/印.png", &pWmFontIds[印]);
		RoadTexture("Texture/WeaponMasterWord/起.png", &pWmFontIds[起]);
		RoadTexture("Texture/WeaponMasterWord/美.png", &pWmFontIds[美]);
		RoadTexture("Texture/WeaponMasterWord/垢.png", &pWmFontIds[垢]);
		RoadTexture("Texture/WeaponMasterWord/対.png", &pWmFontIds[対]);
		RoadTexture("Texture/WeaponMasterWord/象.png", &pWmFontIds[象]);
		RoadTexture("Texture/WeaponMasterWord/独.png", &pWmFontIds[独]);
		RoadTexture("Texture/WeaponMasterWord/吟.png", &pWmFontIds[吟]);
		RoadTexture("Texture/WeaponMasterWord/銀.png", &pWmFontIds[銀]);
		RoadTexture("Texture/WeaponMasterWord/珍.png", &pWmFontIds[珍]);
		RoadTexture("Texture/WeaponMasterWord/最.png", &pWmFontIds[最]);
		RoadTexture("Texture/WeaponMasterWord/高.png", &pWmFontIds[高]);
		RoadTexture("Texture/WeaponMasterWord/低.png", &pWmFontIds[低]);
		RoadTexture("Texture/WeaponMasterWord/討.png", &pWmFontIds[討]);
		RoadTexture("Texture/WeaponMasterWord/射.png", &pWmFontIds[射]);
		RoadTexture("Texture/WeaponMasterWord/狙.png", &pWmFontIds[狙]);
		RoadTexture("Texture/WeaponMasterWord/争.png", &pWmFontIds[争]);
		RoadTexture("Texture/WeaponMasterWord/静.png", &pWmFontIds[静]);
		RoadTexture("Texture/WeaponMasterWord/決.png", &pWmFontIds[決]);
		RoadTexture("Texture/WeaponMasterWord/処.png", &pWmFontIds[処]);
		RoadTexture("Texture/WeaponMasterWord/横.png", &pWmFontIds[横]);
		RoadTexture("Texture/WeaponMasterWord/縦.png", &pWmFontIds[縦]);
		RoadTexture("Texture/WeaponMasterWord/砂.png", &pWmFontIds[砂]);
		RoadTexture("Texture/WeaponMasterWord/遠.png", &pWmFontIds[遠]);
		RoadTexture("Texture/WeaponMasterWord/範.png", &pWmFontIds[範]);
		RoadTexture("Texture/WeaponMasterWord/万.png", &pWmFontIds[万]);
		RoadTexture("Texture/WeaponMasterWord/絞.png", &pWmFontIds[絞]);
		RoadTexture("Texture/WeaponMasterWord/身.png", &pWmFontIds[身]);
		RoadTexture("Texture/WeaponMasterWord/奉.png", &pWmFontIds[奉]);
		RoadTexture("Texture/WeaponMasterWord/太.png", &pWmFontIds[太]);
		RoadTexture("Texture/WeaponMasterWord/世.png", &pWmFontIds[世]);
		RoadTexture("Texture/WeaponMasterWord/巨.png", &pWmFontIds[巨]);
		RoadTexture("Texture/WeaponMasterWord/怪.png", &pWmFontIds[怪]);
		RoadTexture("Texture/WeaponMasterWord/述.png", &pWmFontIds[述]);
		RoadTexture("Texture/WeaponMasterWord/狩.png", &pWmFontIds[狩]);
		RoadTexture("Texture/WeaponMasterWord/爆.png", &pWmFontIds[爆]);
		RoadTexture("Texture/WeaponMasterWord/炎.png", &pWmFontIds[炎]);
		RoadTexture("Texture/WeaponMasterWord/焼.png", &pWmFontIds[焼]);
		RoadTexture("Texture/WeaponMasterWord/灼.png", &pWmFontIds[灼]);
		RoadTexture("Texture/WeaponMasterWord/海.png", &pWmFontIds[海]);
		RoadTexture("Texture/WeaponMasterWord/波.png", &pWmFontIds[波]);
		RoadTexture("Texture/WeaponMasterWord/流.png", &pWmFontIds[流]);
		RoadTexture("Texture/WeaponMasterWord/露.png", &pWmFontIds[露]);
		RoadTexture("Texture/WeaponMasterWord/霜.png", &pWmFontIds[霜]);
		RoadTexture("Texture/WeaponMasterWord/雹.png", &pWmFontIds[雹]);
		RoadTexture("Texture/WeaponMasterWord/風.png", &pWmFontIds[風]);
		RoadTexture("Texture/WeaponMasterWord/疾.png", &pWmFontIds[疾]);
		RoadTexture("Texture/WeaponMasterWord/旋.png", &pWmFontIds[旋]);
		RoadTexture("Texture/WeaponMasterWord/翠.png", &pWmFontIds[翠]);
		RoadTexture("Texture/WeaponMasterWord/輝.png", &pWmFontIds[輝]);
		RoadTexture("Texture/WeaponMasterWord/凪.png", &pWmFontIds[凪]);
		RoadTexture("Texture/WeaponMasterWord/閃.png", &pWmFontIds[閃]);
		RoadTexture("Texture/WeaponMasterWord/耀.png", &pWmFontIds[耀]);
		RoadTexture("Texture/WeaponMasterWord/影.png", &pWmFontIds[影]);
		RoadTexture("Texture/WeaponMasterWord/死.png", &pWmFontIds[死]);
		RoadTexture("Texture/WeaponMasterWord/罪.png", &pWmFontIds[罪]);
		RoadTexture("Texture/WeaponMasterWord/魔.png", &pWmFontIds[魔]);
		RoadTexture("Texture/WeaponMasterWord/斬.png", &pWmFontIds[斬]);
		RoadTexture("Texture/WeaponMasterWord/剣.png", &pWmFontIds[剣]);
		RoadTexture("Texture/WeaponMasterWord/断.png", &pWmFontIds[断]);
		RoadTexture("Texture/WeaponMasterWord/蹴.png", &pWmFontIds[蹴]);
		RoadTexture("Texture/WeaponMasterWord/脚.png", &pWmFontIds[脚]);
		RoadTexture("Texture/WeaponMasterWord/槍.png", &pWmFontIds[槍]);
		RoadTexture("Texture/WeaponMasterWord/牙.png", &pWmFontIds[牙]);
		RoadTexture("Texture/WeaponMasterWord/虚.png", &pWmFontIds[虚]);
		RoadTexture("Texture/WeaponMasterWord/激.png", &pWmFontIds[激]);
		RoadTexture("Texture/WeaponMasterWord/刹.png", &pWmFontIds[刹]);
		RoadTexture("Texture/WeaponMasterWord/華.png", &pWmFontIds[華]);
		RoadTexture("Texture/WeaponMasterWord/羅.png", &pWmFontIds[羅]);
		RoadTexture("Texture/WeaponMasterWord/双.png", &pWmFontIds[双]);
		RoadTexture("Texture/WeaponMasterWord/舞.png", &pWmFontIds[舞]);
		RoadTexture("Texture/WeaponMasterWord/守.png", &pWmFontIds[守]);
		RoadTexture("Texture/WeaponMasterWord/護.png", &pWmFontIds[護]);
		RoadTexture("Texture/WeaponMasterWord/癒.png", &pWmFontIds[癒]);
		RoadTexture("Texture/WeaponMasterWord/無.png", &pWmFontIds[無]);
		RoadTexture("Texture/WeaponMasterWord/乱.png", &pWmFontIds[乱]);
		RoadTexture("Texture/WeaponMasterWord/封.png", &pWmFontIds[封]);
		RoadTexture("Texture/WeaponMasterWord/幻.png", &pWmFontIds[幻]);
		RoadTexture("Texture/WeaponMasterWord/怒.png", &pWmFontIds[怒]);
		RoadTexture("Texture/WeaponMasterWord/鬼.png", &pWmFontIds[鬼]);
		RoadTexture("Texture/WeaponMasterWord/瞬.png", &pWmFontIds[瞬]);
		RoadTexture("Texture/WeaponMasterWord/防.png", &pWmFontIds[防]);
		RoadTexture("Texture/WeaponMasterWord/狼.png", &pWmFontIds[狼]);
		RoadTexture("Texture/WeaponMasterWord/崩.png", &pWmFontIds[崩]);
		RoadTexture("Texture/WeaponMasterWord/壊.png", &pWmFontIds[壊]);
		RoadTexture("Texture/WeaponMasterWord/王.png", &pWmFontIds[王]);
		RoadTexture("Texture/WeaponMasterWord/窮.png", &pWmFontIds[窮]);
		RoadTexture("Texture/WeaponMasterWord/吸.png", &pWmFontIds[吸]);
		RoadTexture("Texture/WeaponMasterWord/救.png", &pWmFontIds[救]);
		RoadTexture("Texture/WeaponMasterWord/殺.png", &pWmFontIds[殺]);
		RoadTexture("Texture/WeaponMasterWord/鳳.png", &pWmFontIds[鳳]);
		RoadTexture("Texture/WeaponMasterWord/蝶.png", &pWmFontIds[蝶]);
		RoadTexture("Texture/WeaponMasterWord/超.png", &pWmFontIds[超]);
		RoadTexture("Texture/WeaponMasterWord/燕.png", &pWmFontIds[燕]);
		RoadTexture("Texture/WeaponMasterWord/堅.png", &pWmFontIds[堅]);
		RoadTexture("Texture/WeaponMasterWord/盾.png", &pWmFontIds[盾]);
		RoadTexture("Texture/WeaponMasterWord/楯.png", &pWmFontIds[楯]);
		RoadTexture("Texture/WeaponMasterWord/鏡.png", &pWmFontIds[鏡]);
		RoadTexture("Texture/WeaponMasterWord/震.png", &pWmFontIds[震]);
		RoadTexture("Texture/WeaponMasterWord/蓮.png", &pWmFontIds[蓮]);
		RoadTexture("Texture/WeaponMasterWord/生.png", &pWmFontIds[生]);
		RoadTexture("Texture/WeaponMasterWord/命.png", &pWmFontIds[命]);
		RoadTexture("Texture/WeaponMasterWord/剋.png", &pWmFontIds[剋]);
		RoadTexture("Texture/WeaponMasterWord/活.png", &pWmFontIds[活]);
		RoadTexture("Texture/WeaponMasterWord/性.png", &pWmFontIds[性]);
		RoadTexture("Texture/WeaponMasterWord/殴.png", &pWmFontIds[殴]);
		RoadTexture("Texture/WeaponMasterWord/桜.png", &pWmFontIds[桜]);
		RoadTexture("Texture/WeaponMasterWord/鋼.png", &pWmFontIds[鋼]);
		RoadTexture("Texture/WeaponMasterWord/皇.png", &pWmFontIds[皇]);
		RoadTexture("Texture/WeaponMasterWord/砕.png", &pWmFontIds[砕]);
		RoadTexture("Texture/WeaponMasterWord/融.png", &pWmFontIds[融]);
		RoadTexture("Texture/WeaponMasterWord/叛.png", &pWmFontIds[叛]);
		RoadTexture("Texture/WeaponMasterWord/固.png", &pWmFontIds[固]);
		RoadTexture("Texture/WeaponMasterWord/狐.png", &pWmFontIds[狐]);
		RoadTexture("Texture/WeaponMasterWord/孤.png", &pWmFontIds[孤]);
		RoadTexture("Texture/WeaponMasterWord/靭.png", &pWmFontIds[靭]);
		RoadTexture("Texture/WeaponMasterWord/詠.png", &pWmFontIds[詠]);
		RoadTexture("Texture/WeaponMasterWord/螺.png", &pWmFontIds[螺]);
		RoadTexture("Texture/WeaponMasterWord/頑.png", &pWmFontIds[頑]);
		RoadTexture("Texture/WeaponMasterWord/鷹.png", &pWmFontIds[鷹]);
		RoadTexture("Texture/WeaponMasterWord/狗.png", &pWmFontIds[狗]);
		RoadTexture("Texture/WeaponMasterWord/破.png", &pWmFontIds[破]);
		RoadTexture("Texture/WeaponMasterWord/灰.png", &pWmFontIds[灰]);
		RoadTexture("Texture/WeaponMasterWord/戦.png", &pWmFontIds[戦]);
		RoadTexture("Texture/WeaponMasterWord/昏.png", &pWmFontIds[昏]);
		RoadTexture("Texture/WeaponMasterWord/恨.png", &pWmFontIds[恨]);
		RoadTexture("Texture/WeaponMasterWord/棍.png", &pWmFontIds[棍]);
		RoadTexture("Texture/WeaponMasterWord/裁.png", &pWmFontIds[裁]);
		RoadTexture("Texture/WeaponMasterWord/鳴.png", &pWmFontIds[鳴]);
		RoadTexture("Texture/WeaponMasterWord/減.png", &pWmFontIds[減]);
		RoadTexture("Texture/WeaponMasterWord/掌.png", &pWmFontIds[掌]);
		RoadTexture("Texture/WeaponMasterWord/導.png", &pWmFontIds[導]);
		RoadTexture("Texture/WeaponMasterWord/隼.png", &pWmFontIds[隼]);
		RoadTexture("Texture/WeaponMasterWord/連.png", &pWmFontIds[連]);
		RoadTexture("Texture/WeaponMasterWord/夢.png", &pWmFontIds[夢]);
		RoadTexture("Texture/WeaponMasterWord/至.png", &pWmFontIds[至]);
		RoadTexture("Texture/WeaponMasterWord/勢.png", &pWmFontIds[勢]);
		RoadTexture("Texture/WeaponMasterWord/砲.png", &pWmFontIds[砲]);
		RoadTexture("Texture/WeaponMasterWord/襲.png", &pWmFontIds[襲]);
		RoadTexture("Texture/WeaponMasterWord/楓.png", &pWmFontIds[楓]);
		RoadTexture("Texture/WeaponMasterWord/霞.png", &pWmFontIds[霞]);
		RoadTexture("Texture/WeaponMasterWord/毒.png", &pWmFontIds[毒]);
		RoadTexture("Texture/WeaponMasterWord/耐.png", &pWmFontIds[耐]);
		RoadTexture("Texture/WeaponMasterWord/騎.png", &pWmFontIds[騎]);
		RoadTexture("Texture/WeaponMasterWord/渾.png", &pWmFontIds[渾]);
		RoadTexture("Texture/WeaponMasterWord/焉.png", &pWmFontIds[焉]);
		RoadTexture("Texture/WeaponMasterWord/凛.png", &pWmFontIds[凛]);
		RoadTexture("Texture/WeaponMasterWord/妖.png", &pWmFontIds[妖]);
		RoadTexture("Texture/WeaponMasterWord/茨.png", &pWmFontIds[茨]);
		RoadTexture("Texture/WeaponMasterWord/棘.png", &pWmFontIds[棘]);
		RoadTexture("Texture/WeaponMasterWord/響.png", &pWmFontIds[響]);
		RoadTexture("Texture/WeaponMasterWord/純.png", &pWmFontIds[純]);
		RoadTexture("Texture/WeaponMasterWord/焔.png", &pWmFontIds[焔]);
		RoadTexture("Texture/WeaponMasterWord/焦.png", &pWmFontIds[焦]);
		RoadTexture("Texture/WeaponMasterWord/蒼.png", &pWmFontIds[蒼]);
		RoadTexture("Texture/WeaponMasterWord/凍.png", &pWmFontIds[凍]);
		RoadTexture("Texture/WeaponMasterWord/嵐.png", &pWmFontIds[嵐]);
		RoadTexture("Texture/WeaponMasterWord/聖.png", &pWmFontIds[聖]);
		RoadTexture("Texture/WeaponMasterWord/天.png", &pWmFontIds[天]);
		RoadTexture("Texture/WeaponMasterWord/星.png", &pWmFontIds[星]);
		RoadTexture("Texture/WeaponMasterWord/闇.png", &pWmFontIds[闇]);
		RoadTexture("Texture/WeaponMasterWord/陰.png", &pWmFontIds[陰]);
		RoadTexture("Texture/WeaponMasterWord/邪.png", &pWmFontIds[邪]);
		RoadTexture("Texture/WeaponMasterWord/冥.png", &pWmFontIds[冥]);
		RoadTexture("Texture/WeaponMasterWord/堕.png", &pWmFontIds[堕]);
		RoadTexture("Texture/WeaponMasterWord/劔.png", &pWmFontIds[劔]);
		RoadTexture("Texture/WeaponMasterWord/剱.png", &pWmFontIds[剱]);
		RoadTexture("Texture/WeaponMasterWord/撃.png", &pWmFontIds[撃]);
		RoadTexture("Texture/WeaponMasterWord/衝.png", &pWmFontIds[衝]);
		RoadTexture("Texture/WeaponMasterWord/穿.png", &pWmFontIds[穿]);
		RoadTexture("Texture/WeaponMasterWord/烈.png", &pWmFontIds[烈]);
		RoadTexture("Texture/WeaponMasterWord/裂.png", &pWmFontIds[裂]);
		RoadTexture("Texture/WeaponMasterWord/獄.png", &pWmFontIds[獄]);
		RoadTexture("Texture/WeaponMasterWord/極.png", &pWmFontIds[極]);
		RoadTexture("Texture/WeaponMasterWord/猛.png", &pWmFontIds[猛]);
		RoadTexture("Texture/WeaponMasterWord/真.png", &pWmFontIds[真]);
		RoadTexture("Texture/WeaponMasterWord/絶.png", &pWmFontIds[絶]);
		RoadTexture("Texture/WeaponMasterWord/魂.png", &pWmFontIds[魂]);
		RoadTexture("Texture/WeaponMasterWord/終.png", &pWmFontIds[終]);
		RoadTexture("Texture/WeaponMasterWord/狂.png", &pWmFontIds[狂]);
		RoadTexture("Texture/WeaponMasterWord/暁.png", &pWmFontIds[暁]);
		RoadTexture("Texture/WeaponMasterWord/神.png", &pWmFontIds[神]);
		RoadTexture("Texture/WeaponMasterWord/竜.png", &pWmFontIds[竜]);
		RoadTexture("Texture/WeaponMasterWord/龍.png", &pWmFontIds[龍]);
		RoadTexture("Texture/WeaponMasterWord/殲.png", &pWmFontIds[殲]);
		RoadTexture("Texture/WeaponMasterWord/剛.png", &pWmFontIds[剛]);
		RoadTexture("Texture/WeaponMasterWord/覇.png", &pWmFontIds[覇]);
		RoadTexture("Texture/WeaponMasterWord/渇.png", &pWmFontIds[渇]);
		RoadTexture("Texture/WeaponMasterWord/煌.png", &pWmFontIds[煌]);
		RoadTexture("Texture/WeaponMasterWord/儘.png", &pWmFontIds[儘]);
		RoadTexture("Texture/WeaponMasterWord/塵.png", &pWmFontIds[塵]);
		RoadTexture("Texture/WeaponMasterWord/鉾.png", &pWmFontIds[鉾]);
		RoadTexture("Texture/WeaponMasterWord/翼.png", &pWmFontIds[翼]);
		RoadTexture("Texture/WeaponMasterWord/轟.png", &pWmFontIds[轟]);
		RoadTexture("Texture/WeaponMasterWord/豪.png", &pWmFontIds[豪]);
		isFirstFrame = 0;
	}


	return;
}

