﻿#include<windows.h>
#include<mbctype.h>
#include"DX9Lib.h"

#include"ControlWordListsAndTyping.h"

void ControlTyping()
{
	static KanaAlphabetTable kanaAlphabetTable[KATAKANA_MAX];
	memset(kanaAlphabetTable,NULL, sizeof(kanaAlphabetTable));

	kanaAlphabetTable[ア] = { "ア","a" };
	kanaAlphabetTable[イ] = { "イ","i","yi" };
	kanaAlphabetTable[ウ] = { "ウ","u","wu" };
	kanaAlphabetTable[エ] = { "エ","e" };
	kanaAlphabetTable[オ] = { "オ","o" };
	kanaAlphabetTable[カ] = { "カ","ka" };
	kanaAlphabetTable[キ] = { "キ","ki" };
	kanaAlphabetTable[ク] = { "ク","ku" };
	kanaAlphabetTable[ケ] = { "ケ","ke" };
	kanaAlphabetTable[コ] = { "コ","ko" };
	kanaAlphabetTable[サ] = { "サ","sa" };
	kanaAlphabetTable[シ] = { "シ","si" };
	kanaAlphabetTable[ス] = { "ス","su" };
	kanaAlphabetTable[セ] = { "セ","se" };
	kanaAlphabetTable[ソ] = { "ソ","so" };
	kanaAlphabetTable[タ] = { "タ","ta" };
	kanaAlphabetTable[チ] = { "チ","ti" };
	kanaAlphabetTable[ツ] = { "ツ","tu" };
	kanaAlphabetTable[テ] = { "テ","te" };
	kanaAlphabetTable[ト] = { "ト","to" };
	kanaAlphabetTable[ナ] = { "ナ","na" };
	kanaAlphabetTable[ニ] = { "ニ","ni" };
	kanaAlphabetTable[ヌ] = { "ヌ","nu" };
	kanaAlphabetTable[ネ] = { "ネ","ne" };
	kanaAlphabetTable[ノ] = { "ノ","no" };
	kanaAlphabetTable[ハ] = { "ハ","ha" };
	kanaAlphabetTable[ヒ] = { "ヒ","hi" };
	kanaAlphabetTable[フ] = { "フ","hu","fu" };
	kanaAlphabetTable[ヘ] = { "ヘ","he" };
	kanaAlphabetTable[ホ] = { "ホ","ho" };
	kanaAlphabetTable[ヴァ] = { "ヴァ","va" };
	kanaAlphabetTable[ヴィ] = { "ヴィ","vi" };
	kanaAlphabetTable[ヴ] = { "ヴ","vu" };
	kanaAlphabetTable[ヴェ] = { "ヴェ","ve" };
	kanaAlphabetTable[ヴォ] = { "ヴォ","vo" };
	kanaAlphabetTable[ファ] = { "ファ","fa" };
	kanaAlphabetTable[フィ] = { "フィ","fi" };
	kanaAlphabetTable[フェ] = { "フェ","fe" };
	kanaAlphabetTable[フォ] = { "フォ","fo" };
	kanaAlphabetTable[マ] = { "マ","ma" };
	kanaAlphabetTable[ミ] = { "ミ","mi" };
	kanaAlphabetTable[ム] = { "ム","mu" };
	kanaAlphabetTable[メ] = { "メ","me" };
	kanaAlphabetTable[モ] = { "モ","mo" };
	kanaAlphabetTable[ヤ] = { "ヤ","ya" };
	kanaAlphabetTable[ユ] = { "ユ","yu" };
	kanaAlphabetTable[イ] = { "イェ","ye" };
	kanaAlphabetTable[ヨ] = { "ヨ","yo" };
	kanaAlphabetTable[ラ] = { "ラ","ra" };
	kanaAlphabetTable[リ] = { "リ","ri" };
	kanaAlphabetTable[ル] = { "ル","ru" };
	kanaAlphabetTable[レ] = { "レ","re" };
	kanaAlphabetTable[ロ] = { "ロ","ro" };
	kanaAlphabetTable[ワ] = { "ワ","wa" };
	kanaAlphabetTable[ウィ] = { "ウィ","wi" };
	kanaAlphabetTable[ウェ] = { "ウェ","we" };
	kanaAlphabetTable[ヲ] = { "ヲ","wo" };
	kanaAlphabetTable[ン] = { "ン","nn" };
	kanaAlphabetTable[ガ] = { "ガ","ga" };
	kanaAlphabetTable[ギ] = { "ギ","gi" };
	kanaAlphabetTable[グ] = { "グ","gu" };
	kanaAlphabetTable[ゲ] = { "ゲ","ge" };
	kanaAlphabetTable[ゴ] = { "ゴ","go" };
	kanaAlphabetTable[ザ] = { "ザ","za" };
	kanaAlphabetTable[ジ] = { "ジ","zi","ji" };
	kanaAlphabetTable[ズ] = { "ズ","zu" };
	kanaAlphabetTable[ゼ] = { "ゼ","ze" };
	kanaAlphabetTable[ゾ] = { "ゾ","zo" };
	kanaAlphabetTable[ダ] = { "ダ","da" };
	kanaAlphabetTable[ヂ] = { "ヂ","di" };
	kanaAlphabetTable[ヅ] = { "ヅ","du" };
	kanaAlphabetTable[デ] = { "デ","de" };
	kanaAlphabetTable[ド] = { "ド","do" };
	kanaAlphabetTable[バ] = { "バ","ba" };
	kanaAlphabetTable[ビ] = { "ビ","bi" };
	kanaAlphabetTable[ブ] = { "ブ","bu" };
	kanaAlphabetTable[ベ] = { "ベ","be" };
	kanaAlphabetTable[ボ] = { "ボ","bo" };
	kanaAlphabetTable[パ] = { "パ","pa" };
	kanaAlphabetTable[ピ] = { "ピ","pi" };
	kanaAlphabetTable[プ] = { "プ","pu" };
	kanaAlphabetTable[ペ] = { "ペ","pe" };
	kanaAlphabetTable[ポ] = { "ポ","po" };
	kanaAlphabetTable[キャ] = { "キャ","kya" };
	kanaAlphabetTable[キィ] = { "キィ","kyi" };
	kanaAlphabetTable[キュ] = { "キュ","kyu" };
	kanaAlphabetTable[キェ] = { "キェ","kye" };
	kanaAlphabetTable[キョ] = { "キョ","kyo" };
	kanaAlphabetTable[シャ] = { "シャ","sya" };
	kanaAlphabetTable[シィ] = { "シィ","syi" };
	kanaAlphabetTable[シュ] = { "シュ","syu" };
	kanaAlphabetTable[シェ] = { "シェ","sye" };
	kanaAlphabetTable[ショ] = { "ショ","syo" };
	kanaAlphabetTable[チャ] = { "チャ","tya" };
	kanaAlphabetTable[チィ] = { "チィ","tyi" };
	kanaAlphabetTable[チュ] = { "チュ","tyu" };
	kanaAlphabetTable[チェ] = { "チェ","tye" };
	kanaAlphabetTable[チョ] = { "チョ","tyo" };
	kanaAlphabetTable[ニャ] = { "ニャ","nya" };
	kanaAlphabetTable[ニィ] = { "ニィ","nyi" };
	kanaAlphabetTable[ニュ] = { "ニュ","nyu" };
	kanaAlphabetTable[ニェ] = { "ニェ","nye" };
	kanaAlphabetTable[ニョ] = { "ニョ","nyo" };
	kanaAlphabetTable[ヒャ] = { "ヒャ","hya" };
	kanaAlphabetTable[ヒィ] = { "ヒィ","hyi" };
	kanaAlphabetTable[ヒュ] = { "ヒュ","hyu" };
	kanaAlphabetTable[ヒェ] = { "ヒェ","hye" };
	kanaAlphabetTable[ヒョ] = { "ヒョ","hyo" };
	kanaAlphabetTable[ミャ] = { "ミャ","mya" };
	kanaAlphabetTable[ミィ] = { "ミィ","myi" };
	kanaAlphabetTable[ミュ] = { "ミュ","myu" };
	kanaAlphabetTable[ミェ] = { "ミェ","mye" };
	kanaAlphabetTable[ミョ] = { "ミョ","myo" };
	kanaAlphabetTable[リャ] = { "リャ","rya" };
	kanaAlphabetTable[リィ] = { "リィ","ryi" };
	kanaAlphabetTable[リュ] = { "リュ","ryu" };
	kanaAlphabetTable[リェ] = { "リェ","rye" };
	kanaAlphabetTable[リョ] = { "リョ","ryo" };
	kanaAlphabetTable[ジャ] = { "ジャ","ja","zya" };
	kanaAlphabetTable[ジュ] = { "ジュ","ju","zyu" };
	kanaAlphabetTable[ジェ] = { "ジェ","je","zye" };
	kanaAlphabetTable[ジョ] = { "ジョ","jo","zyo" };
	kanaAlphabetTable[ジィ] = { "ジィ","zyi" };
	kanaAlphabetTable[ヂャ] = { "ヂャ","dya" };
	kanaAlphabetTable[ヂィ] = { "ヂィ","dyi" };
	kanaAlphabetTable[ヂュ] = { "ヂュ","dyu" };
	kanaAlphabetTable[ヂェ] = { "ヂェ","dye" };
	kanaAlphabetTable[ヂョ] = { "ヂョ","dyo" };
	kanaAlphabetTable[ビャ] = { "ビャ","bya" };
	kanaAlphabetTable[ビィ] = { "ビィ","byi" };
	kanaAlphabetTable[ビュ] = { "ビュ","byu" };
	kanaAlphabetTable[ビェ] = { "ビェ","bye" };
	kanaAlphabetTable[ビョ] = { "ビョ","byo" };
	kanaAlphabetTable[ピャ] = { "ピャ","pya" };
	kanaAlphabetTable[ピィ] = { "ピィ","pyi" };
	kanaAlphabetTable[ピュ] = { "ピュ","pyu" };
	kanaAlphabetTable[ピェ] = { "ピェ","pye" };
	kanaAlphabetTable[ピョ] = { "ピョ","pyo" };
	kanaAlphabetTable[ァ] = { "ァ","la","xa" };
	kanaAlphabetTable[ィ] = { "ィ","li","xi","lyi","xyi" };
	kanaAlphabetTable[ゥ] = { "ゥ","lu","xu" };
	kanaAlphabetTable[ェ] = { "ェ","le","xe","lye","xye" };
	kanaAlphabetTable[ォ] = { "ォ","lo","xo" };
	kanaAlphabetTable[ャ] = { "ャ","lya","xya" };
	kanaAlphabetTable[ュ] = { "ュ","lyu","xyu" };
	kanaAlphabetTable[ョ] = { "ョ","lyo","xyo" };
	kanaAlphabetTable[ッ] = { "ッ","ltu","xtu" };
	kanaAlphabetTable[ー] = { "ー","-" };

	FILE* pWordStatesFile;

	fopen_s(&pWordStatesFile, "Files/WordStates/MagicKnightWordStates.csv", "r");

	//魔法剣士のワードデータ
	WordData magicKnigtWords[MAGIC_KNIGHT_WORD_MAX];

	//初期化
	memset(magicKnigtWords, 0, sizeof(WordData)*MAGIC_KNIGHT_WORD_MAX);

	//魔法剣士のワードデーターを入れていく
	for (int wordsNum = ファイヤー; wordsNum < MAGIC_KNIGHT_WORD_MAX; wordsNum++)
	{
		//外部ファイルの属性を数字に直したいので一度文字列で保管する
		const int ELEMENTAL_WORDS_MAX = 22;
		char elemental[ELEMENTAL_WORDS_MAX];

		const int ATTACK_WORDS_MAX = 4;
		char attack[ATTACK_WORDS_MAX];

		//外部ファイルからの入力
		fscanf_s(pWordStatesFile, "%[^,],%[^,],%[^,],%x", &(magicKnigtWords[wordsNum].m_word), sizeof(char) * WORD_CHAR_MAX, elemental,
			sizeof(char) * ELEMENTAL_WORDS_MAX, attack, sizeof(char)*ATTACK_WORDS_MAX, magicKnigtWords[wordsNum].m_specialAbilities);

		//特殊属性の数だけ回す
		for (int elementalNum = 0; elementalNum < ELEMENT_ATTRIBUTES_MAX; elementalNum)
		{
			//属性が決まったかどうか
			bool wasInputElemental = false;

			//属性を文字列で保管していたので数字に変換する
			switch (elementalNum)
			{
			case FIRE_ELEMENT:

				if (!strcmp("FIRE_ELEMENT", elemental))
				{
					magicKnigtWords[wordsNum].m_element = FIRE_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case WATER_ELEMENT:

				if (!strcmp("WATER_ELEMENT", elemental))
				{
					magicKnigtWords[wordsNum].m_element = WATER_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case WIND_ELEMENT:

				if (!strcmp("WIND_ELEMENT", elemental))
				{
					magicKnigtWords[wordsNum].m_element = WIND_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case SHINING_ELEMENT:

				if (!strcmp("SHINING_ELEMENT", elemental))
				{
					magicKnigtWords[wordsNum].m_element = SHINING_ELEMENT;

					wasInputElemental = true;
				}

				break;

			case DARKNESS_ELEMENT:

				if (!strcmp("DARKNESS_ELEMENT", elemental))
				{
					magicKnigtWords[wordsNum].m_element = DARKNESS_ELEMENT;

					wasInputElemental = true;
				}

				break;
			}

			if (wasInputElemental)
			{
				break;
			}
		}

		//属性がない場合があるのでその対処
		const char VOID_ATTRIBUTE = '0';

		if (elemental[0] = VOID_ATTRIBUTE)
		{
			magicKnigtWords[wordsNum].m_element = VOID_ELEMENT;

			break;
		}

		//物理属性の数だけ回す
		for (int attackNum = 0; attackNum < ATTACK_ATTRIBUTES_MAX; attackNum++)
		{
			bool wasInputAttack = 0;

			switch (attackNum)
			{
			case SLASH_ATTACK:

				if (!strcmp("SLASH_ATTACK", attack))
				{
					magicKnigtWords[wordsNum].m_attack = SLASH_ATTACK;

					wasInputAttack = true;
				}

				break;

			case SMASH_ATTACK:

				if (!strcmp("SLASH_ATTACK", attack))
				{
					magicKnigtWords[wordsNum].m_attack = SLASH_ATTACK;

					wasInputAttack = true;
				}

				break;

			case PENETRATION_ATTACK:

				if (!strcmp("PENETRATION_ATTACK", attack))
				{
					magicKnigtWords[wordsNum].m_attack = PENETRATION_ATTACK;

					wasInputAttack = true;
				}

				break;
			}

			if (wasInputAttack = true)
			{
				break;
			}

		}

		if (elemental[0] = VOID_ATTRIBUTE)
		{
			magicKnigtWords[wordsNum].m_attack = VOID_ATTACK;

			break;
		}
	}

	fclose(pWordStatesFile);

	const int MAGIC_KNIGHT_WORD_LISTS_MAX = 5;

	static WordList magicKnightWordLists[MAGIC_KNIGHT_WORD_LISTS_MAX];

	if (true)
	{
		//単語リストに入る単語の生成
		for (int listWord = 0; listWord < MAGIC_KNIGHT_WORD_LISTS_MAX; listWord++)
		{
			//ワードenumにVOID_WORDが入ってるので-1、+1してる
			magicKnightWordLists[listWord].m_Id = (MAGIC_KNIGHT_WORD)(rand() % (MAGIC_KNIGHT_WORD_MAX - 1) + 1);
		}
	}

	//何番目の単語か
	static int wordNum = 0;

	//単語の文字の何番目まで打たれているか
	static int wordSpellPos = 0;
	static MagicKnightAction magicKnightAction;
	memset(&magicKnightAction, 0, sizeof(MagicKnightAction));
	const int INPUT_CHAR_LIMIT = 5;

	for (; magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] != 0; wordSpellPos++)
	{
		if (wordSpellPos > WORD_CHAR_MAX - INPUT_CHAR_LIMIT - 1)
		{
			goto canInputCharMax;
		}
	}

	for (BYTE keyId = DIK_MINUS; keyId <= DIK_M; keyId++)
	{
		if (g_keyState.keyPush[keyId])
		{
			switch (keyId)
			{
			case DIK_A:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'a';

				wordSpellPos++;

				break;

			case DIK_B:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'b';

				wordSpellPos++;

				break;

			case DIK_C:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'c';

				wordSpellPos++;

				break;


			case DIK_D:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'd';

				wordSpellPos++;

				break;

			case DIK_E:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'e';

				wordSpellPos++;

				break;

			case DIK_F:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'f';

				wordSpellPos++;

				break;

			case DIK_G:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'g';

				wordSpellPos++;

				break;

			case DIK_H:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'h';

				wordSpellPos++;

				break;

			case DIK_I:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'i';

				wordSpellPos++;

				break;

			case DIK_J:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'j';

				wordSpellPos++;

				break;

			case DIK_K:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'k';

				wordSpellPos++;

				break;

			case DIK_L:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'l';

				wordSpellPos++;

				break;

			case DIK_M:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'm';

				wordSpellPos++;

				break;

			case DIK_N:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'n';

				wordSpellPos++;

				break;

			case DIK_O:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'o';

				wordSpellPos++;

				break;

			case DIK_P:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'p';

				wordSpellPos++;

				break;

			case DIK_Q:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'q';

				wordSpellPos++;

				break;

			case DIK_R:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'r';

				wordSpellPos++;

				break;

			case DIK_S:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 's';

				wordSpellPos++;

				break;

			case DIK_T:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 't';

				wordSpellPos++;

				break;

			case DIK_U:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'u';

				wordSpellPos++;

				break;

			case DIK_V:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'v';

				wordSpellPos++;

				break;

			case DIK_W:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'w';

				wordSpellPos++;

				break;

			case DIK_X:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'x';

				wordSpellPos++;

				break;

			case DIK_Y:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'y';

				wordSpellPos++;

				break;

			case DIK_Z:

				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos] = 'z';

				wordSpellPos++;

				break;

			case DIK_MINUS:

				memcpy_s(&magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos], sizeof(char)*MULTI_BYTE,
					"ー", sizeof(char)*MULTI_BYTE);

				wordSpellPos += MULTI_BYTE;

				break;

			case DIK_BACK:

				if (wordSpellPos > 0)
				{
					//ここで二バイト文字の場合一文字だけ消しても意味ない関数があったからそれを使う_ismbblead　１バイト目　_ismbbtrail 2ばいとめ
					if (_ismbbtrail(magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 1]))
					{
						magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 1] = NULL;
						magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 2] = NULL;

						wordSpellPos -= MULTI_BYTE;
					}

					else
					{
						magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 1] = NULL;

						wordSpellPos--;
					}
				}

				break;
			}
		}
	}

canInputCharMax:
	if (g_keyState.keyPush[DIK_BACK])
	{
		if (wordSpellPos > 0)
		{
			if (_ismbbtrail(magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 1]))
			{
				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 1] = NULL;
				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 2] = NULL;

				wordSpellPos -= MULTI_BYTE;
			}

			else
			{
				magicKnightAction.m_inputWords[wordNum].m_word[wordSpellPos - 1] = NULL;

				wordSpellPos--;
			}
		}
	}

	//タイピングした文字をカタカナに変換する
	for (int charNum = 0;magicKnightAction.m_inputWords[wordNum].m_word[charNum] != NULL;++charNum)
	{
		for (int kana = 0; kana < KATAKANA_MAX; ++kana)
		{
			for (int alphabet = 0; alphabet < ESTIMATE_ALPHABET_MAX; ++alphabet)
			{
				//範囲外対処
				if (!strlen(&kanaAlphabetTable[kana].m_alphabet[alphabet].m_alphabet[0]))
				{
					continue;
				}

				//打たれた文字とテーブルにある文字が対応していないかチェック
				if (strncmp(&magicKnightAction.m_inputWords[wordNum].m_word[charNum],
					&kanaAlphabetTable[kana].m_alphabet[alphabet].m_alphabet[0],
					strlen(&kanaAlphabetTable[kana].m_alphabet[alphabet].m_alphabet[0])))
				{
					continue;
				}

				int alphabetSize = strlen(&kanaAlphabetTable[kana].m_alphabet[alphabet].m_alphabet[0]);

				int charShiftNum = strlen(&kanaAlphabetTable[kana].m_katakana[0]) - 
					strlen(&kanaAlphabetTable[kana].m_alphabet[alphabet].m_alphabet[0]);

				for (int charShiftTarget = WORD_CHAR_MAX - 1; 
					charShiftTarget >= charNum + alphabetSize+ charShiftNum; --charShiftTarget)
				{
					magicKnightAction.m_inputWords[wordNum].m_word[charShiftTarget] = 
						magicKnightAction.m_inputWords[wordNum].m_word[charShiftTarget- charShiftNum];
				}

				strncpy(&magicKnightAction.m_inputWords[wordNum].m_word[charNum],
					&kanaAlphabetTable[kana].m_katakana[0], strlen(&kanaAlphabetTable[kana].m_katakana[0]));

				break;
			}

			//同じアルファベットが並んだ場合"ッ"を入れる 直前の処理で母音はすべてカタカナに変換されているので考慮せずとも良い
			if (strncmp(&magicKnightAction.m_inputWords[wordNum].m_word[charNum],
				&magicKnightAction.m_inputWords[wordNum].m_word[charNum + 1], 1))
			{
				continue;
			}

			const int ONE_SHIFT = 1;

			for (int charShiftTarget = WORD_CHAR_MAX - 1; 
				charShiftTarget >= charNum + (MULTI_BYTE+ sizeof(char))+ ONE_SHIFT; --charShiftTarget)
			{
				magicKnightAction.m_inputWords[wordNum].m_word[charShiftTarget] =
					magicKnightAction.m_inputWords[wordNum].m_word[charShiftTarget - ONE_SHIFT];
			}

			strncpy(&magicKnightAction.m_inputWords[wordNum].m_word[charNum + MULTI_BYTE],
				&magicKnightAction.m_inputWords[wordNum].m_word[charNum], sizeof(char));

			strncpy(&magicKnightAction.m_inputWords[wordNum].m_word[charNum],"ッ", MULTI_BYTE+ sizeof(char));
		}
	}

	//単語にアルファベットのルビを振る
	int wordCandidatePos = 0;

	//文字が入力されていない場合抜ける
	if (!magicKnightAction.m_inputWords[wordNum].m_word[0])
	{
		goto cantEstimated;
	}

	//すでにカナが連続で何文字打たれているのか
	for (int charNum = 0; charNum < WORD_CHAR_MAX; ++charNum)
	{
		if (!_ismbblead(magicKnightAction.m_inputWords[wordNum].m_word[charNum]))
		{
			break;
		}

		wordCandidatePos += MULTI_BYTE;
	}
	
	//カナの次にアルファベットその次にカナがあった場合単語リストと一致しないため抜ける
	for (int charNum = wordCandidatePos; charNum < WORD_CHAR_MAX; ++charNum)
	{
		if (_ismbblead(magicKnightAction.m_inputWords[wordNum].m_word[charNum]))
		{
			goto cantEstimated;
		}
	}

	WordCandidate wordCandidates[MAGIC_KNIGHT_WORD_LISTS_MAX];
	memset(wordCandidates, 0, sizeof(wordCandidates));

	//リストの単語と入力文字の一致が複数ある場合があるので回す
	for (int listWordNum = 0; listWordNum < MAGIC_KNIGHT_WORD_LISTS_MAX; ++listWordNum)
	{
		//カナ部分がなしの場合通らない
		if (!wordCandidatePos)
		{
			//カナの部分でリストにあるかチェック
			if (!strncmp(&magicKnightAction.m_inputWords[wordNum].m_word[0],
				&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[0], wordCandidatePos))
			{
				//チェックをして単語リストにあった場合カナの部分をルビにコピー
				strncpy(&wordCandidates[listWordNum].m_ruby[0],
					&magicKnightAction.m_inputWords[wordNum].m_word[0], wordCandidatePos);

				goto copiedWord;
			}

			//リストにないとループさせて最終的に抜ける
			else
			{
				continue;
			}
		}
		
	copiedWord:

		//一致するカナを探す
		//カナの優先順位的に最大値から始める
		for (int kana = KATAKANA_MAX - 1; kana >= 0; --kana)
		{
			//調べるカナの位置
			int kanaPos = wordCandidatePos;

			//文字を回している
			for (int rubyCount = 0; rubyCount < (WORD_CHAR_MAX / MULTI_BYTE); rubyCount++)
			{
				//カナ以外の文字が打たれているか判別
				//打たれている場合
				if (strlen(&magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos]))
				{
					//ッの場合
					if (!strncmp(&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[kanaPos], "ッ", MULTI_BYTE) && (
						magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos] != 'x' ||
						magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos] != 'l'))
					{
						//リストにある文字と同じかチェック
						if (!magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos + 1])
						{
							goto cantEstimated;
						}

						//カタカナを回す
						for (int kataKana = 0; kataKana < KATAKANA_MAX; kataKana++)
						{
							//ッの次のカナを調べる
							if (!strncmp(&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[kanaPos + MULTI_BYTE],
								&kanaAlphabetTable[kataKana].m_katakana[0],
								strlen(&kanaAlphabetTable[kataKana].m_katakana[0])))
							{
								//アルファベットの差分を回す
								for (int estimate = 0; estimate < ESTIMATE_ALPHABET_MAX; estimate++)
								{
									//範囲外チェック
									if (!strlen(&kanaAlphabetTable[kataKana].m_alphabet[estimate].m_alphabet[0]))
									{
										continue;
									}

									//アルファベットのチェック
									if (strncmp(&magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos],
										&kanaAlphabetTable[kataKana].m_alphabet[estimate].m_alphabet[0], sizeof(char)))
									{
										//直前の処理で調べたカナを構成しているアルファベットの一番目の文字
										strncpy(&wordCandidates[listWordNum].m_ruby[wordCandidatePos],
											&kanaAlphabetTable[kataKana].m_alphabet[estimate].m_alphabet[0], sizeof(char));

										//直前の処理で調べたカナ
										strncpy(&wordCandidates[listWordNum].m_ruby[wordCandidatePos + 1],
											&kanaAlphabetTable[kataKana].m_alphabet[estimate].m_alphabet[0],
											strlen(&kanaAlphabetTable[kataKana].m_alphabet[estimate].m_alphabet[0]));

										kanaPos += MULTI_BYTE + strlen(&kanaAlphabetTable[kataKana].m_katakana[0]);

										wordCandidatePos += strlen(&wordCandidates[listWordNum].m_ruby[wordCandidatePos]);

										goto inputtedRuby;
									}
								}
							}
						}
					}

					else
					{
						for (int kana = KATAKANA_MAX - 1; kana >= 0; --kana)
						{
							//アルファベットの差分を回す
							for (int estimate = 0; estimate < ESTIMATE_ALPHABET_MAX; estimate++)
							{
								//範囲外チェック
								if (!strlen(&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0]))
								{
									continue;
								}

								//入力した文字とアルファベットを比較して対応するカナを探す
								//ずっと入らなかったらアウト
								if (!strncmp(&magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos],
									&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0],
									strlen(&magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos])))
								{
									if(!strncmp(&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[wordCandidatePos],
										&kanaAlphabetTable[kana].m_katakana[wordCandidatePos],
										strlen(&kanaAlphabetTable[kana].m_katakana[wordCandidatePos])))
									{
										goto canEstimate;
									}
								}

								else
								{
									//最後まで行って対応するカナを探せなかったらアウト
									if (kana == 0)
									{
										goto cantEstimated;
									}
								}
							}
						}

						canEstimate:

						//アルファベットの差分を回す
						for (int estimate = 0; estimate < ESTIMATE_ALPHABET_MAX; estimate++)
						{
							//範囲外チェック
							if (!strlen(&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0]))
							{
								continue;
							}

							//入力した文字とアルファベットを比較して対応するアルファベットを探す
							if (!strncmp(&magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos],
								&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0],
								strlen(&magicKnightAction.m_inputWords[wordNum].m_word[wordCandidatePos])))
							{
								//対応していたアルファベットを入れる
								strncpy(&wordCandidates[listWordNum].m_ruby[wordCandidatePos],
									&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0],
									strlen(&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0]));

								//カタカナのポジション 入れたアルファベットのカナの分増やす
								kanaPos += strlen(&kanaAlphabetTable[kana].m_katakana[0]);

								//アルファベットポジション 入れたアルファベット分増加
								wordCandidatePos +=
									strlen(&kanaAlphabetTable[kana].m_alphabet[estimate].m_alphabet[0]);

								goto inputtedRuby;
							}
						}
					}

				}
				else
				{
					//カタカナを回す
					for (int katakana = 0; katakana < KATAKANA_MAX; katakana++)
					{
						//カタカナを比較する
						if (!strncmp(&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[kanaPos],
							&kanaAlphabetTable[katakana].m_katakana[0],
							strlen(&kanaAlphabetTable[katakana].m_katakana[0])))
						{
							//ッの場合
							if (!strncmp(&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[kanaPos],
								"ッ", MULTI_BYTE))
							{
								//カタカナを回す
								for (int kataKana = 0; kataKana < KATAKANA_MAX; kataKana++)
								{
									//ッの次のカナを調べる
									if (!strncmp(&magicKnigtWords[magicKnightWordLists[listWordNum].m_Id].m_word[kanaPos + MULTI_BYTE],
										&kanaAlphabetTable[kataKana].m_katakana[0],
										strlen(&kanaAlphabetTable[kataKana].m_katakana[0])))
									{
										//直前の処理で調べたカナを構成しているアルファベットの一番目の文字
										strncpy(&wordCandidates[listWordNum].m_ruby[wordCandidatePos],
											&kanaAlphabetTable[katakana].m_alphabet[0].m_alphabet[0], sizeof(char));

										//直前の処理で調べたカナ
										strncpy(&wordCandidates[listWordNum].m_ruby[wordCandidatePos + 1],
											&kanaAlphabetTable[katakana].m_alphabet[0].m_alphabet[0],
											strlen(&kanaAlphabetTable[katakana].m_alphabet[0].m_alphabet[0]));

										kanaPos += MULTI_BYTE + strlen(&kanaAlphabetTable[katakana].m_katakana[0]);

										wordCandidatePos += strlen(&wordCandidates[listWordNum].m_ruby[wordCandidatePos]);

										goto inputtedRuby;
									}
								}
							}

							//比較したカナに対応したアルファベットを入れる
							strncpy(&wordCandidates[listWordNum].m_ruby[wordCandidatePos],
								&kanaAlphabetTable[katakana].m_alphabet[0].m_alphabet[0],
								strlen(&kanaAlphabetTable[katakana].m_alphabet[0].m_alphabet[0]));

							kanaPos += strlen(&kanaAlphabetTable[katakana].m_katakana[0]);

							wordCandidatePos += strlen(&wordCandidates[listWordNum].m_ruby[wordCandidatePos]);

							goto inputtedRuby;
						}
					}
				}

			inputtedRuby:
			}
		}
	}

	cantEstimated:

	if(g_keyState.keyPush[DIK_RETURN])
	{
		wordNum++;
	}
}
