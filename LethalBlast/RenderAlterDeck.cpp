﻿#define _CRT_SECURE_NO_WARNINGS
#include"DX9Lib.h"
#include"WinMain.h"
#include"ControlCharaChoice.h"
#include"CharactarInfo.h"
#include"ControlAlterDeck.h"
#include"RenderAlterDeck.h"

void RenderAlterDeck(ImagesCustomVertex* pChoiseWordCollisionsVertex, ImagesCustomVertex* pDeckComponentCollisionsVertex, ImagesCustomVertex* pSkillInfo,
	CustomVertex* endDeckAlterVertices,CustomVertex* pBackgroundVertices, CustomVertex* pWordDatasBackVertices,
	TEXTUREID* wordTexIds, WordData* pPlayerWordDatas, PlayerDeck* pPlayerDecks, int* pDeckNumToAlter, bool* clickedWord, bool* pChoiceWordData)
{
	static TEXTUREID alterDeckTexId[ALTER_DECK_TEX_MAX];
	static TEXTUREID explanationFontId[SKILL_MAX];

	static FONTID fontId[1];

	static int frameCount = INIT_FRAME;

	if (frameCount == INIT_FRAME)
	{
		RoadTexture("Texture/AlterDeck/EndAlterDeck.png", &alterDeckTexId[EXIT_ALTER_TEX]);
		RoadTexture("Texture/AlterDeck/DeckAlterBackground1.jpg", &alterDeckTexId[ALTER_BACK_1_TEX]);
		RoadTexture("Texture/AlterDeck/DeckAlterBackground2.png", &alterDeckTexId[ALTER_BACK_2_TEX]);
		RoadTexture("Texture/AlterDeck/DeckAlterBackground3.png", &alterDeckTexId[ALTER_BACK_3_TEX]);
		RoadTexture("Texture/AlterDeck/RedFrame.png", &alterDeckTexId[ALTER_CLICKED_EFFECT_TEX]);
		RoadTexture("Texture/AlterDeck/UnderAlterWordBoard.png", &alterDeckTexId[UNDER_ALTER_WORD_BOARD_TEX]);
		RoadTexture("Texture/AlterDeck/DeckAlterTag.jpg", &alterDeckTexId[DECK_ALTER_TAG_TEX]);
		RoadTexture("Texture/MainGame/PageCursol.png", &alterDeckTexId[CURSOL_TEX]);

		RoadTexture("Texture/AlterDeck/explanationFont/mojicost1_50.png", &explanationFontId[MPプラス２]);
		RoadTexture("Texture/AlterDeck/explanationFont/mojicost2_50.png", &explanationFontId[被ダメ２５％カット]);
		RoadTexture("Texture/AlterDeck/explanationFont/mojicost3_50.png", &explanationFontId[２５％回復]);
		RoadTexture("Texture/AlterDeck/explanationFont/mojicost4_50.png", &explanationFontId[次の与ダメ１．３倍]);
		RoadTexture("Texture/AlterDeck/explanationFont/mojicost5_50.png", &explanationFontId[与ダメ１．１倍]);
		RoadTexture("Texture/AlterDeck/explanationFont/mojicost6_50.png", &explanationFontId[追撃２５％]);
		RoadTexture("Texture/AlterDeck/explanationFont/mojicost7_50.png", &explanationFontId[今１．４倍次０．８倍]);

		SetFont(DISPLAY_WIDTH / 70, DISPLAY_WIDTH / 70, "HGP明朝B", &fontId,0);

		frameCount = 0;
	}

	CustomVertex alterBackVertices[4];
	CustomImageVerticies(alterBackVertices, DISPLAY_WIDTH / 2.f, DISPLAY_HEIGHT / 2.f, DISPLAY_WIDTH / 2.f, DISPLAY_HEIGHT / 2.f);
	
	DrawImage(alterBackVertices, alterDeckTexId[ALTER_BACK_1_TEX]);
	
	for (int wordNum = 0; wordNum < MAGIC_KNIGHT_WORD_MAX; ++wordNum)
	{
		DrawImage(pChoiseWordCollisionsVertex[wordNum].ImageVertex, alterDeckTexId[UNDER_ALTER_WORD_BOARD_TEX]);
		DrawImage(pChoiseWordCollisionsVertex[wordNum].ImageVertex, mKWordTex[wordNum]);

		if (clickedWord[wordNum])
		{
			DrawImage(pChoiseWordCollisionsVertex[wordNum].ImageVertex, alterDeckTexId[ALTER_CLICKED_EFFECT_TEX]);
		}
	}
	
	DrawImage(alterBackVertices, alterDeckTexId[ALTER_BACK_2_TEX]);

	for (int deckNum = 0; deckNum < DECK_WORD_MAX; ++deckNum)
	{
		DrawImage(pDeckComponentCollisionsVertex[deckNum].ImageVertex, alterDeckTexId[UNDER_ALTER_WORD_BOARD_TEX]);

		if (pPlayerDecks[(*pDeckNumToAlter)].m_wordIds[deckNum])
		{
			DrawImage(pDeckComponentCollisionsVertex[deckNum].ImageVertex, wordTexIds[(pPlayerDecks[(*pDeckNumToAlter)].m_wordIds[deckNum])]);
		}
	}
	
	DrawImage(alterBackVertices, alterDeckTexId[ALTER_BACK_3_TEX]);

	CustomVertex deckAlterTag[RECT_VERTEX_NUM];
	CustomImageVerticies(deckAlterTag, DISPLAY_WIDTH / 2.f, DISPLAY_HEIGHT*0.04f, DISPLAY_WIDTH / 2.f, DISPLAY_HEIGHT*0.04f);

	DrawImage(deckAlterTag,alterDeckTexId[DECK_ALTER_TAG_TEX]);

	CustomVertex cursol[4];
	const float CURSOL_POSX = DISPLAY_WIDTH * 0.7f;
	const float CURSOL_SCALE = DISPLAY_WIDTH * 0.025f;

	for (int wordDatas = 0; wordDatas < MAGIC_KNIGHT_WORD_MAX; ++wordDatas)
	{
		if (pChoiceWordData[wordDatas] = true)
		{
			DrawImage(pChoiseWordCollisionsVertex[wordDatas].ImageVertex, wordTexIds[wordDatas]);

			for (int costConfig = 1;costConfig < 3;++costConfig)
			{
				switch (costConfig)
				{
				case 1:
					CustomImageVerticies(cursol, CURSOL_POSX, DISPLAY_HEIGHT*0.7f, CURSOL_SCALE, CURSOL_SCALE);
					RotateImageDeg(cursol, cursol, 180.f);

					DrawImage(cursol, alterDeckTexId[CURSOL_TEX]);
					
					break;

				case 2:
					CustomImageVerticies(cursol, CURSOL_POSX + DISPLAY_WIDTH * 0.1f, DISPLAY_HEIGHT*0.7f, CURSOL_SCALE, CURSOL_SCALE);

					DrawImage(cursol, alterDeckTexId[CURSOL_TEX]);

					break;
				}

			}

			for (int skill = MPプラス２;skill < SKILL_MAX;++skill)
			{
				DrawImage(pSkillInfo[skill].ImageVertex, explanationFontId[skill]);
			}

			char cost[10];
			sprintf(cost, "%d", pPlayerWordDatas[wordDatas].m_costMax);

			WriteText(DISPLAY_WIDTH * 0.75, DISPLAY_HEIGHT * 0.7, cost, DT_RIGHT, fontId[0]);
		}
	}

	WriteText(DISPLAY_WIDTH * 0.8, DISPLAY_HEIGHT * 0.7, "/12", DT_RIGHT, fontId[1]);

	DrawImage(endDeckAlterVertices, alterDeckTexId[EXIT_ALTER_TEX]);

	return;
}

//void RenderWeaponMasterAlterDeck(ImagesCustomVertex* pChoiseWordCollisionsVertex, ImagesCustomVertex* pDeckComponentCollisionsVertex,
//	CustomVertex* endDeckAlterVertices, CustomVertex* pBackgroundVertices, CustomVertex* pWordDatasBackVertices,
//	TEXTUREID* wordTexIds, WeaponMasterWordData* pWeaponMasterWordDatas, WeaponMasterDeck* pWeaponMasterDecks, int* pDeckNumToAlter, bool* clickedWord)
//{
//	static TEXTUREID weaponMasterAlterTextureIds[ALTER_DECK_TEX_MAX];
//	static FONTID descriptionFontIds;
//
//	static int isFirstFrame = INIT_FRAME;
//
//	if (isFirstFrame == INIT_FRAME)
//	{
//		RoadTexture("Texture/AlterDeck/WMAlterDeck1.png", &weaponMasterAlterTextureIds[WM_ALTER_BACK_1_TEX]);
//		RoadTexture("Texture/MainGame/ListBG.png", &weaponMasterAlterTextureIds[WM_ALTER_BACK_2_TEX]);
//		RoadTexture("Texture/AlterDeck/EndAlterDeck.png", &weaponMasterAlterTextureIds[EXIT_ALTER_TEX]);
//		RoadTexture("Texture/AlterDeck/RedFrame.png", &weaponMasterAlterTextureIds[ALTER_CLICKED_EFFECT_TEX]);
//		RoadTexture("Texture/AlterDeck/DeckAlterTag.jpg", &weaponMasterAlterTextureIds[DECK_ALTER_TAG_TEX]);
//		RoadTexture("Texture/AlterDeck/DescriptionBack.png", &weaponMasterAlterTextureIds[WM_ALTER_BACK_3_TEX]);
//
//		SetFont(DISPLAY_WIDTH / 70, DISPLAY_WIDTH / 70, "HGP明朝B", &descriptionFontIds, 0);
//		
//		isFirstFrame = 0;
//	}
//
//	DrawImage(pWordDatasBackVertices, weaponMasterAlterTextureIds[WM_ALTER_BACK_1_TEX]);
//	DrawImage(pBackgroundVertices, weaponMasterAlterTextureIds[WM_ALTER_BACK_2_TEX]);
//
//	for (int wordNum = 0; wordNum < WEAPON_MASTER_WORD_MAX; ++wordNum)
//	{
//		DrawImage(pChoiseWordCollisionsVertex[wordNum].ImageVertex, wordTexIds[wordNum]);
//
//		if (clickedWord[wordNum])
//		{
//			DrawImage(pChoiseWordCollisionsVertex[wordNum].ImageVertex, weaponMasterAlterTextureIds[ALTER_CLICKED_EFFECT_TEX]);
//		}
//	}
//
//	for (int deckNum = 0; deckNum < DECK_WORD_MAX; ++deckNum)
//	{
//		if (pWeaponMasterDecks[(*pDeckNumToAlter)].m_wordIds[deckNum])
//		{
//			DrawImage(pDeckComponentCollisionsVertex[deckNum].ImageVertex, wordTexIds[(pWeaponMasterDecks[(*pDeckNumToAlter)].m_wordIds[deckNum])]);
//		}
//	}
//
//	CustomVertex deckAlterTag[RECT_VERTEX_NUM];
//	CustomImageVerticies(deckAlterTag, DISPLAY_WIDTH / 2.f, DISPLAY_HEIGHT*0.04f, DISPLAY_WIDTH / 2.f, DISPLAY_HEIGHT*0.04f);
//
//	DrawImage(deckAlterTag, weaponMasterAlterTextureIds[DECK_ALTER_TAG_TEX]);
//
//	CustomVertex descriptionBack[RECT_VERTEX_NUM];
//	CustomImageVerticies(descriptionBack, DISPLAY_WIDTH - (DISPLAY_WIDTH / 3.f), DISPLAY_HEIGHT - (DISPLAY_HEIGHT / 6.f), DISPLAY_WIDTH / 3.f, DISPLAY_HEIGHT / 6.f);
//
//	DrawImage(descriptionBack, weaponMasterAlterTextureIds[WM_ALTER_BACK_3_TEX]);
//
//	/*マウスカーソルとの当たり判定用の頂点設定 開始*/
//
//	//マウスカーソル
//	CustomVertex mouseCursorCollisionVertex[RECT_VERTEX_NUM];
//
//	const float MOUSE_CURSOR_SCALE = 0.5f;
//	CustomImageVerticies(mouseCursorCollisionVertex, (float)g_mouseState.absolutePos.x, (float)g_mouseState.absolutePos.y, MOUSE_CURSOR_SCALE, MOUSE_CURSOR_SCALE);
//
//	const DWORD FONT_COLOR = 0xFF000000;
//
//	for (int wordDatas = 0; wordDatas < WEAPON_MASTER_WORD_MAX; ++wordDatas)
//	{
//		if (RectToRectCollisionCheak(mouseCursorCollisionVertex, pWordDatasBackVertices))
//		{
//			if (RectToRectCollisionCheak(mouseCursorCollisionVertex, pChoiseWordCollisionsVertex[wordDatas].ImageVertex))
//			{
//				const int ELEMENT_POS_X = (int)(DISPLAY_WIDTH*0.5f);
//				const int ELEMENT_POS_Y = (int)(DISPLAY_HEIGHT*0.8f);
//
//				switch (pWeaponMasterWordDatas[wordDatas].m_element)
//				{
//				case FIRE_ELEMENT:
//
//					WriteText(ELEMENT_POS_X, ELEMENT_POS_Y, "特殊 火", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//
//				case WATER_ELEMENT:
//
//					WriteText(ELEMENT_POS_X, ELEMENT_POS_Y, "特殊 水", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//
//				case WIND_ELEMENT:
//
//					WriteText(ELEMENT_POS_X, ELEMENT_POS_Y, "特殊 風", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//
//				case DARKNESS_ELEMENT:
//
//					WriteText(ELEMENT_POS_X, ELEMENT_POS_Y, "特殊 闇", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//
//				case SHINING_ELEMENT:
//
//					WriteText(ELEMENT_POS_X, ELEMENT_POS_Y, "特殊 光", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//				}
//
//				const int ATTACK_POS_X = (int)(DISPLAY_WIDTH*0.65f);
//				const int ATTACK_POS_Y = (int)(DISPLAY_HEIGHT*0.8f);
//
//				switch (pWeaponMasterWordDatas[wordDatas].m_attack)
//				{
//				case SLASH_ATTACK:
//
//					WriteText(ATTACK_POS_X, ATTACK_POS_Y, "物理 斬", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//
//				case SMASH_ATTACK:
//
//					WriteText(ATTACK_POS_X, ATTACK_POS_Y, "物理 打", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//
//				case PENETRATION_ATTACK:
//
//					WriteText(ATTACK_POS_X, ATTACK_POS_Y, "物理 突", DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//					break;
//				}
//
//				char cost[20] = "コスト";
//				sprintf(&cost[6], "%d", pWeaponMasterWordDatas[wordDatas].m_cost);
//
//				WriteText((int)(DISPLAY_WIDTH*0.8f), (int)(DISPLAY_HEIGHT*0.8f), cost, DT_CENTER, descriptionFontIds, FONT_COLOR);
//
//				break;
//			}
//		}
//		
//	}
//
//	DrawImage(endDeckAlterVertices, weaponMasterAlterTextureIds[EXIT_ALTER_TEX]);
//}