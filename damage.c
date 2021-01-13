/*!
 * damage.c
 *
 * Copyright (c) 2021  Yui Tsubaki
 *
 * Released under the MIT licence.
 * see https://opensource.org/licenses/MIT
 */

#include<stdio.h>
#include<string.h>

typedef struct _DATA{
	char name[40];	//キャラクター名
	int damage;	//基準ダメージ値
	char type;	//魔法属性
} DATA;

int dataregist(DATA *, int);
float datacalc(DATA *, int);

int main()
{
	DATA name[500] = {
		{"リドル", 7142, 'H'}, {"エース", 6024, 'K'},
		{"デュース", 4592, 'M'}, {"ケイト", 5481, 'H'},
		{"トレイ", 4038, 'K'}, {"レオナ", 6877, 'K'},
		{"ジャック", 6255, 'K'}, {"ラギー", 4949, 'M'},
		{"アズール", 5388, 'M'}, {"ジェイド", 4880, 'H'},
		{"フロイド", 5885, 'K'}, {"カリム", 5670, 'M'},
		{"ジャミル", 6133, 'H'}
	};
	int data_num = 13;	//初期登録数
	int mode = 0;	//モード

/***************************************
 モード選択
****************************************/ 
	printf("-------戦闘ダメージ計算ツール-------\n属性入力は火ならＨ、木ならＫ，水ならＭを入力してください\n");
	while(1){
		printf("キャラ情報の登録は1を、計算は2を、終了は0を入力してください:");
		scanf("%d", &mode);
		if(mode == 0)
			break;
		else if(mode == 1)
			data_num = dataregist(name, data_num);
		else if(mode == 2)
			printf("総ダメージ:%6.2f \n\n", datacalc(name, data_num));
	}
	return 0;
}


/***************************************
 dataregist() キャラクターリスト登録する
 [引数] pname--キャラクターリストへのポインタ
 	num--登録前のリストの要素数
 [戻り値]登録前のリストの要素数
 ***************************************/
int dataregist(DATA *pname, int num)
{
	printf("キャラクター名を入力してください: ");
	scanf("%s", (pname+num)->name);
	printf("そのキャラのアタック値を入力してください: ");
	scanf("%d", &((pname+num)->damage));
	printf("魔法属性を入力してください: ");
	scanf("%s", &((pname+num)->type));
	printf("登録しました。\n\n");
	return num+1;
}

/****************************************
 datacalc() ダメージを計算する
 [引数] pname--キャラリストへのポインタ
 	num--リストの要素数
 [戻り値] ダメージ値
 ****************************************/
float datacalc(DATA *pname, int num)
{
	char name[40];
	float totaldamage = 0.0;   //総ダメージ値
	char ytype;	//敵属性
	int i;
	


	printf("--キャラクター一覧-------------\n");
	for(i = 0; i < num; i++)
		printf("%s\n", (pname+i)->name);
	printf("\n-----------------------------\n");
	
	printf("敵属性を入力してください:");
	scanf("%s", &ytype);

	switch(ytype){
	case 'H':
	while(1){
		printf("キャラクター名(endで計算):");
		scanf("%s", name);
		if(strcmp(name, "end") == 0)
			break;
		for(i = 0; i < num; i++){
			if(strcmp(name, (pname+i)->name) == 0){
				switch((pname+i)->type){
				case 'H':
					totaldamage += (pname+i)->damage;
					break;
				case 'M':
					totaldamage += (pname+i)->damage * 2;
					break;
				case 'K':
					totaldamage  += (pname+i)->damage * 0.5;
					break;
				}
			}
		}
		}
	break;

	case 'M':
	while(1){
		printf("キャラクター名(endで計算):");
		scanf("%s", name);
		if(strcmp(name, "end") == 0)
			break;
		for(i = 0; i < num; i++){
			if(strcmp(name, (pname+i)->name) == 0){
				switch((pname+i)->type){
				case 'H':
					totaldamage += (pname+i)->damage * 0.5;
					break;
				case 'M':
					totaldamage += (pname+i)->damage;
					break;
				case 'K':
					totaldamage += (pname+i)->damage * 2;
					break;
				}
			}
		}
		}
	break;

	case 'K':
	while(1){
		printf("キャラクター名(endで計算):");
		scanf("%s", name);
		if(strcmp(name, "end") == 0)
			break;
		for(i = 0; i < num; i++){
			if(strcmp(name, (pname+i)->name) == 0){
				switch((pname+i)->type){
				case 'H':
					totaldamage += (pname+i)->damage * 2;
					break;
				case 'M':
					totaldamage += (pname+i)->damage * 0.5;
					break;
				case 'K':
					totaldamage += (pname+i)->damage;
					break;
				}
			}
		}
		}
	break;
	}
	return totaldamage;
}


