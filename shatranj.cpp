// shatranj.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<time.h>
using namespace std;
char map[6][6];
bool readfile(char, char map[6][6], char*);
int writefile(char, char map[6][6], char*);
bool sarbaz_move(int satr, int sotoon, char map[6][6]);
bool sarbaz_2_move(int satr, int sotoon, char map[6][6]);
void checkplayer(char, int[], int[], int[], int[], int[], int[], int[], int[], char[], char map[6][6], const int, const int);
void mohrehayeharif(char, char*, char*, int[], int[], int[], int[], int[], int[], int[], int[], char map[6][6], int, int);
bool zarbsarbaz(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char*khodi, int*satrsarbazjadid, int* sotoonsarbazjadid, bool khataryab);
bool zarbsarbaz2(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char*khodi, int*satrsarbazjadid, int* sotoonsarbazjadid, bool khataryab);
bool sarbaz_move(int, int, char map[6][6]);
bool sarbaz_can_move(char, int, int, char map[6][6]);
bool sarbaz_easy(int, int, char, char map[6][6], char*);
bool sarbaz_2_easy(int, int, char, char map[6][6], char*);
bool asb_easy(int*, int, int, char, char map[6][6], char*, int*, int*, bool);
bool vazir_easy(int* meghdarforkhatar, char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, int khodicount, bool khataryab);//is_our dare(be return falsash dobare deghat kon)
bool checkzarb(char setplayer, int satr, int sotoon, char sarnam, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6]);
void vazir_easy_easy(int* jahat, int satr, int sotoon, int jahathayemojaz[], int meghdarharekat[], int khodicount, char* khodi, int satrmohre, int sotoonmohre, char sarnammohre);
//bool vazir_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* khatar, int* meghdarharekati = 0, bool khataryab = false);
bool zarbasb(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char* khodi, int* satrasbjadid, int* sotoonasbjadid, bool khataryab = false);
bool vazir_move(int satr, int sotoon, int jahat, int i, char map[6][6]);
bool zarbvazir(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char* khodi, int* satrjadid, int* sotoonjadid, bool khataryab);
void aya_zadan_ghable_farar_amn_ast(int harifsatr, int harifsotoon, char setplayer, int mohafezchist, int satrmohrekhodi, int sotoonmohrekhodi, char map[6][6], char copyofmap1[6][6], char nammohre);

bool is_our(char, char*);
bool checkzarbsarbaz(char setplayer, int satrharif, int sotoonharif, int satrmahaljadid, int sotoonmahalejadid, char map[6][6], char);
bool checkzarbasb(int satrharif, int sotoonharif, int satrmahaljadid, int sotoonmahaljadid);
bool checkzarbvazir(int satrharif, int sotoonharif, int satrmahaljadid, int sotoonmahaljadid, char[6][6], char);
bool vazir_dar_khatar_ast(char setplayer, int satrghararbeharekat, int sotoonghararbeharekat, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int vazirsatr, int vazirsotoon, char map[6][6]);
bool asb_dar_khatar_ast(int setplayer, int satrghararbeharekat, int sotoonghararbeharekat, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int asbsatr, int asbsotoon, char map[6][6]);
bool mohafez_darad(char setplayer, int mohafezchist, int satrmohafez, int sotoonmohafez, int satrmahaljadid, int sotoonmahaljadid, char map[6][6]);
bool mohafez_darad_2(int vazirnewsatr, int vazirnewsotoon, char setplayer, int mohafezchist, int satrmohafez, int sotoonmohafez, int satrmahaljadid, int sotoonmahaljadid, char map[6][6], char vazirnammm);

void search_mohre_darkhatar(char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int vazirmojood, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int asbsatr, int asbsotoon, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2sotoon, int sarbaz1nam, int sarbaz2satr, int sarbaz2nam, int vazirsatr, int vazirsotoon, int asbnam, char vazirnammm, bool* sarbaz1darkhatar, bool* sarbaz2darkhatar, bool* asbdarkhatar, bool* vazirdarkhatar);
bool vazir_easy_for_khatar(int satrmohre, int sotoonmohre, char* khodi, int jahat, int vazirsatr, int vazirsotoon, char sarnam, int meghdarharekat, char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char sarbaz1nam, char sarbaz2nam, char asbnam);
bool mohafez_ghabelzadane(char sarnammohremohafez, int satrmohreavvali, int sotoonmohreavvali, char setplayer, int satrmohafez, int sotoonmohafez, int satrmahaljadid, int sotoonmahaljadid, char map[6][6], int sarbaz1harif,
	int sarbaz2harif, int asbharif, int  vazirharif, int  sarbaz1harifsatr, int sarbaz1harifsotoon, int  sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon
	, int vazirharifsatr, int vazirharifsotoon);
bool mohre_kojaye_vazire(int* jahatmohrekhodi, int satrmohre, int sotoonmohre, int satrvazir, int sotoonvazir, char map[6][6]);
void aya_mitavanad_sade_harekat(char setplayer, int noemohre, int satrmohre, int sotoonmohre, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon, int vazirsatr, int vazirsotoon, bool* aya_mohre_mohafez_s1, bool* aya_mohre_mohafez_s2, bool* aya_mohre_mohafez_asb, bool* aya_mohre_mohafez_vazir, char map[6][6]);
bool can_zarb_for_tahdid(char setplayer, int noemohre, int sarbaz1newsatr, int sarbaz1newsotoon, char sarbaz1nam, int sarbaz2newsatr, int sarbaz2newsotoon
	, char sarbaz2nam, int asbnewsatr, int asbnewsotoon, int vazirnewsatr, int vazirnewsotoon, char vazirnammm, int sarbaz1harif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harif
	, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharif, int asbharifsatr, int asbharifsotoon, int vazirharif, int vazirharifsatr, int vazirharifsotoon);

//bool vazir_trial_func(int,int,int,int,int*,int*);
int main(int argc, char* argv[])
{
	/*
	//harekat vazir moshkel dare(mipare)//ehtemalan hal shode
	//player1 midim meghdar sotoon manfi mishe 
	//harekat sade darnazar nagereftim
	//khali kardan mohre ghabli bara hame check kon
	//harekat sade vazir moonde
	//true bedi tabe tamoom mishe bebin oonjahaei ke ++ dadi tadakhol nagire havaset bashe be inke akolad kojas shyd dorost bashe
	//tabe harekat sade vazir neveshte shode ama takmil(argomana ina) mikhad 
	//bad be in fekr bash ke ba harekat sade chikar koni 
	//hatman az ghabl check beshe 
	//badha baraye shomaresh anasor araye az sizeof estefade kon
	//check returnaye asb easy(ta inja benazaram mohem nist)
	//KHATE572
	//harekat sade anjam nmishe 
	//tabe zarb vazir moshkel dare----hal shod taghriban
	//tabesadef harekat eshtebah mizane
	//	srand(time(0));
	//int player = 1 + rand() % 2;
	//easya moshkel daran asb va sarbaz(2ta baham miran)
	//for vazir easy kar nmikone
	//do moshkel asasi vazireasy az mohreha mipare
	//yeharekat asb eshtebah chap be bala
	//b to harekat sade bazi vaghta az naghshe pak mishe
	//zarb asb to ye ja mipare
	//zarb vazir khub kar nmikone
	//maghadiri ke be tabe midio deghat konnn/
	//zarbsarbaz mipare
	//age mogheyat bashe roo harekat sade asb klid mikone ye shomarande mikhad
	//tabezarbvazir darjahat rast khali ejra nmishe
	//tabe easy vazir az chap be rast moshkel darad
	//mogheyat khatar baraye asb moonde ye taghirati too asb_easy() dadam ama engar karsaz nist 
	//hamin asbo mogheyate khatar besazim halle
	//baragard va oonjahaei ke ba while va mote m kar kardi check kon ke <5 va >0 bashe
	*/
	char* filename = argv[2];
	char player = *argv[1];
	//int player = 2;
	if (readfile(player, map, filename))
	{
		writefile(player, map, filename);
	}
	else
		cout << "error";


}
bool readfile(char setplayer, char map[6][6], char* fname)
{
	char ch = 'k';
	char mohre[8];
	int ii = 0, cj = 0, dj = 0;
	int a[2] = { 0 }, b[2] = { 0 }, e[2] = { 0 }, f[2] = { 0 }, c1[2] = { 0 }, c2[2] = { 0 }, d1[2] = { 0 }, d2[2] = { 0 };
	int m1 = 0, m2 = 0;//baraye dashtan tedad mohrehaye har 2bazikon
	ifstream in(fname, ios::in);
	if (!in)
		cout << "Error For Read File";


	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			in >> ch;
			map[i][j] = ch;
			if (ch == 'a')
			{
				mohre[ii] = 'a';
				a[0] = i;
				a[1] = j;
				ii++;
				m1++;
			}
			else if (ch == 'b')
			{
				mohre[ii] = 'b';
				b[0] = i;
				b[1] = j;
				ii++;
				m2++;
			}
			else if (ch == 'e')
			{
				mohre[ii] = 'e';
				e[0] = i;
				e[1] = j;
				ii++;
				m1++;
			}
			else if (ch == 'f')
			{
				mohre[ii] = 'f';
				f[0] = i;
				f[1] = j;
				ii++;
				m2++;
			}
			else if (ch == 'c'&&cj == 0)//cj baraye in ghozashtam ta tashkhis bede sarbaz1 ya 2
			{
				mohre[ii] = 'g';
				//faghat characteresho avaz kardm
				c1[0] = i;
				c1[1] = j;
				ii++;
				cj++;
				m1++;
			}
			else if (ch == 'c')
			{
				mohre[ii] = 'h';
				c2[0] = i;
				c2[1] = j;
				ii++;
				m1++;
			}
			else if (ch == 'd'&&dj == 0)
			{
				mohre[ii] = 'k';
				d1[0] = i;
				d1[1] = j;
				ii++;
				dj++;
				m2++;
			}
			else if (ch == 'd')
			{
				mohre[ii] = 'l';
				d2[0] = i;
				d2[1] = j;
				ii++;
				m2++;
			}
		}

	}

	//cout << a[1];
	//for (int cc = 0; cc < m1 + m2; cc++)
	//cout << mohre[cc]<<endl;
	////cin >> mohre;
	//cout << "m1" << m1;
	checkplayer(setplayer, e, f, a, b, c1, c2, d1, d2, mohre, map, m1, m2);
	return true;

}
void checkplayer(char setplayer, int e[], int f[], int a[], int b[], int c1[], int c2[], int d1[], int d2[], char mohre[], char map[6][6], const int m1, const int m2)
{
	int harifcount = 0, khodicount = 0;
	char* gp1;
	gp1 = new char[m1];
	char* gp2;
	gp2 = new char[m2];
	//char gp1[m1];
	//char gp2[m2];
	int ii = 0, iii = 0;
	char* khodi;
	char* harif;
	//if (setplayer == '1')
	//	MovePlayer1(map);
	//else
	//	MovePlayer2(map);

	for (int i = 0; i <m1 + m2; i++)
	{

		if (mohre[i] == 'a' || mohre[i] == 'e' || mohre[i] == 'g' || mohre[i] == 'h')
		{
			gp1[ii] = mohre[i];
			ii++;
		}
		else if (mohre[i] == 'b' || mohre[i] == 'f' || mohre[i] == 'k' || mohre[i] == 'l')
		{
			gp2[iii] = mohre[i];
			iii++;
		}
	}
	if (setplayer == '1')
	{
		khodi = gp1; harif = gp2;
		khodicount = m1;
		harifcount = m2;
	}
	else { khodi = gp2; harif = gp1; khodicount = m2; harifcount = m1; }
	//mohrehaye harifo az inja seda bezan

	//cout << harif[0];
	//cin >> khodi;
	mohrehayeharif(setplayer, harif, khodi, e, f, a, +b, c1, c2, d1, d2, map, khodicount, harifcount);
}
void mohrehayeharif(char setplayer, char* harif, char* khodi, int e[], int f[], int a[], int b[], int c1[], int c2[], int d1[], int d2[], char map[6][6], int khodicount, int harifcount)
{
	bool sarbaz1, sarbaz2 = false, asb = false, vazir = false;
	bool sarbaz1mojood = false, sarbaz2mojood = false, asbmojood = false, vazirmojood = false;//baraye vojood dashtan ya nadashtan mohrehaye khodi
	char costn[4];
	int cost[4] = { 0 };
	int satr = 0, sotoon = 0;
	//	char sarsarnam, vazirsarnam;
	//char asbsarnam;
	char sarbaz1nam, sarbaz2nam, asbnam, vazirnammm;
	int sarbaz1satr = 0, sarbaz1sotoon = 0, sarbaz2satr = 0, sarbaz2sotoon = 0, asbsatr = 0, asbsotoon = 0, vazirsatr = 0, vazirsotoon = 0;
	char vazirharifnam, asbharifnam, sarbaz1harifnam, sarbaz2harifnam;
	int vazirharifsatr, vazirharifsotoon, asbharifsatr, asbharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon;//gereftan ettelat harif
	bool vazirharif = false, asbharif = false, sarbaz1harif = false, sarbaz2harif = false;//check mojoodiate mohrehaye harif
	bool sarbaz1foreasy = false, sarbaz2foreasy = false, asbforeasy = false, vazirforeasy = false;
	bool cangofromsarbaz1 = false;
	bool cangofromsarbaz2 = false;
	bool cangofromasb = false;
	bool cangofromvazir = false;
	if (!sarbaz1harif)
		cangofromsarbaz1 = true;
	if (!sarbaz2harif)
		cangofromsarbaz2 = true;
	if (!asbharif)
		cangofromasb = true;
	if (!vazirharif)
		cangofromvazir = true;
	for (int i = 0; i < harifcount; i++)
	{
		if (harif[i] == 'a' || harif[i] == 'b') {
			vazirharif = true;
			vazirharifnam = harif[i];
			if (harif[i] == 'a') {
				vazirharifsatr = a[0];
				vazirharifsotoon = a[1];
			}
			else if (harif[i] == 'b')
			{
				vazirharifsatr = b[0];
				vazirharifsotoon = b[1];
			}
			cost[0] = 15;
			costn[0] = harif[i];
		}
		if (harif[i] == 'e' || harif[i] == 'f') {
			asbharif = true;
			asbharifnam = harif[i];
			if (harif[i] == 'e') {
				asbharifsatr = e[0];
				asbharifsotoon = e[1];
			}
			else if (harif[i] == 'f') {
				asbharifsatr = f[0];
				asbharifsotoon = f[1];
			}
			cost[1] = 10;
			costn[1] = harif[i];
		}

		//	if (harif[i] == 'g' || harif[i] == 'h' || harif[i] == 'k' || harif[i] == 'l') {
		//	cost[2] = 5;
		//costn[2] = harif[i];
		//	}
		if (harif[i] == 'g')
		{
			sarbaz1harif = true;
			sarbaz1harifnam = harif[i];
			sarbaz1harifsatr = c1[0];
			sarbaz1harifsotoon = c1[1];
			cost[2] = 5;
			costn[2] = 'c';
		}
		if (harif[i] == 'k')
		{
			sarbaz1harif = true;
			sarbaz1harifnam = harif[i];
			sarbaz1harifsatr = d1[0];
			sarbaz1harifsotoon = d1[1];
			cost[2] = 5;
			costn[2] = 'd';
		}
		if (harif[i] == 'h')
		{
			sarbaz2harif = true;
			sarbaz2harifnam = harif[i];
			sarbaz2harifsatr = c2[0];
			sarbaz2harifsotoon = c2[1];
			cost[3] = 4;
			costn[3] = 'c';
		}
		if (harif[i] == 'l')
		{
			sarbaz2harif = true;
			sarbaz2harifnam = harif[i];
			sarbaz2harifsatr = d2[0];
			sarbaz2harifsotoon = d2[1];
			cost[3] = 4;
			costn[3] = 'd';
		}
	}
	for (int j = 0; j < khodicount; j++) {

		if (khodi[j] == 'g') {
			sarbaz1nam = 'c';
			sarbaz1satr = c1[0];
			sarbaz1sotoon = c1[1];
			sarbaz1mojood = true;
		}
		else if (khodi[j] == 'h')
		{
			sarbaz2nam = 'c';
			sarbaz2satr = c2[0];
			sarbaz2sotoon = c2[1];
			sarbaz2mojood = true;
		}
		else if (khodi[j] == 'k') {
			sarbaz1nam = 'd';
			sarbaz1satr = d1[0];
			sarbaz1sotoon = d1[1];
			sarbaz1mojood = true;
		}
		else if (khodi[j] == 'l')
		{
			sarbaz2nam = 'd';
			sarbaz2satr = d2[0];
			sarbaz2sotoon = d2[1];
			sarbaz2mojood = true;
		}
		else if (khodi[j] == 'e')
		{
			asbnam = 'e';
			asbsatr = e[0];
			asbsotoon = e[1];
			asbmojood = true;
		}
		else if (khodi[j] == 'f')
		{
			asbnam = 'f';
			asbsatr = f[0];
			asbsotoon = f[1];
			asbmojood = true;
		}
		else if (khodi[j] == 'a')
		{
			vazirnammm = 'a';
			vazirsatr = a[0];
			vazirsotoon = a[1];
			vazirmojood = true;
		}
		else if (khodi[j] == 'b') {
			vazirnammm = 'b';
			vazirsatr = b[0];
			vazirsotoon = b[1];
			vazirmojood = true;
		}
	}
	/*
	for (int bb = 0; bb <khodicount; bb++)
		cout << khodi[bb];
	cout << khodicount;
	cin >> khodi;
	moshkel ine ke 2ta vazir mindaze
	*/
	bool easyallow = true;
	bool yekharekat = false;//motmaein shim easya yek harekat mizann
	sarbaz1 = false;//mabnaro gozashtim hich kodoom nistn
	sarbaz2 = false;
	asb = false;
	vazir = false;
	
	bool canescapefromsarbaz1 = false, canescapefromsarbaz2 = false, canescapefromasb = false, canescapefromvazir = false;
	int satrasbjadid, sotoonasbjadid;
	int satrsarbazjadid, sotoonsarbazjadid;
	bool vazirgo = false;
	bool yekharekatmojazzarb = true;
	bool edamebadekhatar = true;
	int vz_t = 1;//gozahstm ta jolo erroro begiram
				 /*if (vazirmojood == true) {

				 //اينو گذاشتم تا همون اول بازي ببينه وزيرجاي خطرناکي هست يا نه اگه بود سريعا با يه حرکت ساده جاش عوض شه
				 int meghdarharekati = 0;
				 int khatarvazir;
				 int vazirnewsatr = 0, vazirnewsotoon = 0;
				 //1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
				 bool vazir_easyy;
				 int jahatvazir = 1;
				 if (sarbaz1harif)
				 cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirsatr, vazirsotoon);
				 if (sarbaz2harif)
				 cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirsatr, vazirsotoon);
				 if (asbharif)
				 cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirsatr, vazirsotoon);
				 if (vazirharif)
				 cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon);
				 if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false) {

				 for (int jahatvazir2 = 0; jahatvazir2 < 8; jahatvazir2++) {
				 vazir_easyy = vazir_easy(&jahatvazir, vazirsatr, vazirsotoon, vazirnammm, map, khodi, &vazirnewsatr, &vazirnewsotoon, true);
				 //bool vazir_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* khatar, int* meghdarharekati = 0, bool khataryab = false)
				 //بيايم بگيم  يه جهت  ساده تو قسمت ايزي الو تعريف کنيم
				 //بعد بعد چک کردن 4 کن گو و ايف اصلي بگيم اگه ايف نقض شد
				 //تو السش اول جهت يکي اضافه بشه بعد دوباره وزير فور ايزي اجرا ببشه
				 //تا زماني ک ايف اصليمون (4تا شرطه)ترو بشه
				 //براي بقيه مهرهام همينکارو بکن

				 cout << "\nvazirNew" << jahatvazir;
				 if (sarbaz1harif)
				 cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirnewsatr, vazirnewsotoon);
				 if (sarbaz2harif)
				 cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirnewsatr, vazirnewsotoon);
				 if (asbharif)
				 cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
				 if (vazirharif)
				 cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon);
				 //	cout << cangofromasb;//5 mide
				 //cin >> khatar;

				 if (vazir_easyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
				 vazirforeasy = vazir_easy(&jahatvazir, vazirsatr, vazirsotoon, vazirnammm, map, khodi, &vazirnewsatr, &vazirnewsotoon, false);
				 vazirgo = true;
				 break;

				 }
				 else {
				 //if (jahatvazir == 8)
				 //vazirforeasy = false;

				 jahatvazir++;
				 //							vazirforeasy = false;
				 }
				 }//forjahatvazir
				 }
				 }
				 */
				 //if (vazirgo == false) {
	if (!sarbaz1harif)
		canescapefromsarbaz1 = true;
	if (!sarbaz2harif)
		canescapefromsarbaz2 = true;
	if (!asbharif)
		canescapefromasb = true;
	if (!vazirharif)
		canescapefromvazir = true;
	/////////////////////////قبل از حرکت ضربي از امنيت وزير و اسب بايد مطمئن شي
	//اول باید بدونیم محافظت اسب و سرباز برای وزیر بی معنیه
	bool sarbazz_can_move = false;

	if (easyallow == true && vazirmojood == true) {
		//همون اول چک کن اگه وزیر بجای فرار میتونه مهره ای روامن بزنه مهره بزنه
		bool harekatzarbidare = false;

		bool can_zarb_vazir = mohafez_darad(setplayer, 2, vazirsatr, vazirsotoon, vazirharifsatr, vazirharifsotoon, map);
		if (can_zarb_vazir == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(vazirharifsatr, vazirharifsotoon, setplayer, 2, vazirsatr, vazirsotoon, map, copyofmap1, vazirnammm);
			bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirharifsatr, vazirharifsotoon, copyofmap1, asbnam);
			bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirharifsatr, vazirharifsotoon, copyofmap1, asbnam);
			bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon);
			if (_cangofromsarbaz1 == true && _cangofromsarbaz2 == true && _cangofromasb == true)
			{
				harekatzarbidare = true;
			}
		}
		////////////
		////
		bool can_zarb_asb = mohafez_darad(setplayer, 2, vazirsatr, vazirsotoon, asbharifsatr, asbharifsotoon, map);
		if (can_zarb_asb == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(asbharifsatr, asbharifsotoon, setplayer, 2, vazirsatr, vazirsotoon, map, copyofmap1, vazirnammm);
			bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, vazirnammm);
			bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, vazirnammm);
			bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, vazirnammm);
			if (_cangofromsarbaz1 == true && _cangofromsarbaz2 == true && _cangofromvazir == true)
			{
				harekatzarbidare = true;
			}
		}
		///////////////////
		bool can_zarb_sarbaz1 = mohafez_darad(setplayer, 2, vazirsatr, vazirsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map);
		if (can_zarb_sarbaz1 == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(sarbaz1harifsatr, sarbaz1harifsotoon, setplayer, 2, vazirsatr, vazirsotoon, map, copyofmap1, asbnam);
			//	bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
			bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
			bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon);
			bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
			if (_cangofromvazir == true && _cangofromsarbaz2 == true && _cangofromasb == true)
			{
				harekatzarbidare = true;
			}
		}
		////////////////////////
		bool can_zarb_sarbaz2 = mohafez_darad(setplayer, 2, vazirsatr, vazirsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, map);
		if (can_zarb_sarbaz2 == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(sarbaz2harifsatr, sarbaz2harifsotoon, setplayer, 2, vazirsatr, vazirsotoon, map, copyofmap1, asbnam);
			bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, copyofmap1, asbnam);
			//	bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
			bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon);
			bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, copyofmap1, asbnam);
			if (_cangofromvazir == true && _cangofromsarbaz1 == true && _cangofromasb == true)
			{
				harekatzarbidare = true;
			}
		}
		////////////////////
		//حالا یکاری میکنیم ک اگه اسب درخطر بود و میتونه با امنیت مهره ای رو بزنه  دیگه فرارش کار نکنه و ضربی عمل کنه
		///
		if (harekatzarbidare == false) {

			///////////////////////////////////////////////////////////////
			bool vz_mohafez_s1 = false, vz_mohafez_s2 = false, vz_mohafez_asb = false;
			int countvazirzarbpazir = 0;
			int tedadmohafezvazir = 0;
			//اينو گذاشتم تا همون اول بازي ببينه وزيرجاي خطرناکي هست يا نه اگه بود سريعا با يه حرکت ساده جاش عوض شه
			int meghdarharekati = 0;
			//	int khatarvazir;
			int vazirnewsatr = 0, vazirnewsotoon = 0;
			//1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
			bool vazir_easyy;
			int jahatvazir = 1;
			if (sarbaz1harif)
				cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirsatr, vazirsotoon, map, vazirnammm);
			if (sarbaz2harif)
				cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirsatr, vazirsotoon, map, vazirnammm);
			if (asbharif)
				cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirsatr, vazirsotoon);
			if (vazirharif)
				cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map, vazirnammm);
			if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false) {//cangofromvazir == false hazf shod ta beshe vaziro ba harchi zad hata vazir ba vazir
				bool vaziravvalmohafezdarad = false;//ino gozashtm ta hamoonavvalcheckkone ke agevazirmohafezdashtaslan harekatesh nade
				if (sarbaz1mojood)
				{
					bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
					if (mohafezsarbaz1)
						vaziravvalmohafezdarad = true;
				}//if sarbaz1mojood
				if (sarbaz2mojood)
				{
					bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
					if (mohafezsarbaz2)
						vaziravvalmohafezdarad = true;
				}
				if (asbmojood)
				{
					bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
					if (mohafezasb)
						vaziravvalmohafezdarad = true;
				}
				if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false)
					vaziravvalmohafezdarad = false;
				//بگیم اگه حریف اسب بود یا سرباز ک بخواد وزیرو بزنه دیگه محافظت سرباز واسب بیخوده
				if (vaziravvalmohafezdarad == false) {//vaziragehichmohafezinadashtharekatkone
					int jahathayeamn[8] = { 0 };
					int shomareshamn = 0;

					for (int jahatvazir2 = 0; jahatvazir2 < 8; jahatvazir2++) {

						//bool vazir_easy(char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, int khodicount, bool khataryab, bool)
						vazir_easyy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);
						if (vazir_easyy == true)
						{
							//	cout << endl << " jahat" << jahatvazir << jahatvazir2;


							if (sarbaz1mojood) {//چک میکنیم ک دراین جهت آیا وزیرمیتونه محافظ سرباز یک بشه یانه
								vz_mohafez_s1 = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, sarbaz1satr, sarbaz2satr, map);
							}
							if (sarbaz2mojood)
							{
								vz_mohafez_s2 = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, sarbaz2satr, sarbaz2sotoon, map);
							}
							if (asbmojood)
							{
								vz_mohafez_asb = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, asbsatr, asbsotoon, map);
							}
							if (vz_mohafez_asb == false && vz_mohafez_s1 == false && vz_mohafez_s2 == false)
							{
								jahathayeamn[shomareshamn] = jahatvazir;
								shomareshamn++;
								jahatvazir++;
								continue;

							}
							if (vz_mohafez_asb == true)
							{
								//	cout << "moasb";
								break;
							}
							if (vz_mohafez_s1 == true || vz_mohafez_s2 == true)
							{
								//	cout << "mo";
								break;

							}

						}
						//bool vazir_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* khatar, int* meghdarharekati = 0, bool khataryab = false)
						//بيايم بگيم  يه جهت  ساده تو قسمت ايزي الو تعريف کنيم
						//بعد بعد چک کردن 4 کن گو و ايف اصلي بگيم اگه ايف نقض شد
						//تو السش اول جهت يکي اضافه بشه بعد دوباره وزير فور ايزي اجرا ببشه
						//تا زماني ک ايف اصليمون (4تا شرطه)ترو بشه
						//براي بقيه مهرهام همينکارو بکن
						//	cin >> yekharekat;
						//بیا چک کن وزیر تو جهت جدید محافظ مهره ای میشه یا نه اگه اره خب همون بزن اگه نه جهت امنو تو یه ارایه ذخیره کن و بعدا ازش استفاده کن
						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
						if (cangofromsarbaz1 == false)
							countvazirzarbpazir += 1;
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
						if (cangofromsarbaz2 == false)
							countvazirzarbpazir += 1;
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
						if (cangofromasb == false)
							countvazirzarbpazir += 1;
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
						if (cangofromvazir == false)
							countvazirzarbpazir += 1;
						//	cout << jahatvazir<<endl;//5 mide
						//cin >> yekharekat;
						if (vazir_easyy == true && cangofromvazir == false || cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false)
						{
							bool vazirmohafezdarad = false;
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, vazirnewsatr, vazirnewsotoon, map);
								if (mohafezsarbaz1 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, vazirsatr, vazirsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, vazirnewsatr, vazirnewsotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazirmohafezdarad = true;
										tedadmohafezvazir += 1;
									}
								}
							}//if sarbaz1mojood
							if (sarbaz2mojood)
							{

								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, vazirnewsatr, vazirnewsotoon, map);
								if (mohafezsarbaz2 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, vazirsatr, vazirsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, vazirnewsatr, vazirnewsotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazirmohafezdarad = true;
										tedadmohafezvazir += 1;
									}

								}
							}
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, vazirnewsatr, vazirnewsotoon, map);
								if (mohafezasb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, vazirsatr, vazirsotoon, setplayer, asbsatr, asbsotoon, vazirnewsatr, vazirnewsotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazirmohafezdarad = true;
										tedadmohafezvazir += 1;
									}
								}
							}
							if (vazirmohafezdarad == true && tedadmohafezvazir >= countvazirzarbpazir)
							{

								vazirforeasy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, false);
								easyallow = false;
								yekharekat = true;
								edamebadekhatar = false;
								break;
							}

						}
						if (vazir_easyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
							//	bool vazir_easy(char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, bool khataryab)
							vazirforeasy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, false);
							easyallow = false;
							yekharekat = true;
							edamebadekhatar = false;
							break;

						}
						else {
							//if (jahatvazir == 8)
							//vazirforeasy = false;

							jahatvazir++;
							//							vazirforeasy = false;
						}
					}//forjahatvazir
				}
			}
			//hala check mikonim ke aya vazir amn hast ya na
		}//ifvazirmojood
		 ////////////////////////////
	}
	///////////////////////////////////////اومدیم گفتیم قبل از فرار اسب با وزیر ازش محافظت کن
	if (easyallow == true && yekharekat == false) {

		bool harekatzarbidare = false;
		bool can_zarb_vazir = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, vazirharifsatr, vazirharifsotoon, map);
		if (can_zarb_vazir == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(vazirharifsatr, vazirharifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
			bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirharifsatr, vazirharifsotoon, copyofmap1, asbnam);
			bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirharifsatr, vazirharifsotoon, copyofmap1, asbnam);
			bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon);
			if (_cangofromsarbaz1 == true && _cangofromsarbaz2 == true && _cangofromasb == true)
			{
				harekatzarbidare = true;
			}
		}
		////////////
		////
		bool can_zarb_asb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, asbharifsatr, asbharifsotoon, map);
		if (can_zarb_asb == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(asbharifsatr, asbharifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
			bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
			bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
			bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
			if (_cangofromsarbaz1 == true && _cangofromsarbaz2 == true && _cangofromvazir == true)
			{
				harekatzarbidare = true;
			}
		}
		///////////////////
		bool can_zarb_sarbaz1 = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map);
		if (can_zarb_sarbaz1 == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(sarbaz1harifsatr, sarbaz1harifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
			//	bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
			bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
			bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon);
			bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
			if (_cangofromvazir == true && _cangofromsarbaz2 == true && _cangofromasb == true)
			{
				harekatzarbidare = true;
			}
		}
		////////////////////////
		bool can_zarb_sarbaz2 = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, map);
		if (can_zarb_sarbaz2 == true)
		{
			char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
			aya_zadan_ghable_farar_amn_ast(sarbaz2harifsatr, sarbaz2harifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
			bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, copyofmap1, asbnam);
			//	bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
			bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon);
			bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, copyofmap1, asbnam);
			if (_cangofromvazir == true && _cangofromsarbaz1 == true && _cangofromasb == true)
			{
				harekatzarbidare = true;
			}
		}
		////////////////////
		//حالا یکاری میکنیم ک اگه اسب درخطر بود و میتونه با امنیت مهره ای رو بزنه  دیگه فرارش کار نکنه و ضربی عمل کنه
		///
		if (harekatzarbidare == false) {
			bool sarbaz1mohafezeshe = false, sarbaz2mohafezeshe = false, vazirmohafezeshe = false, asbmohafezeshe = false;
			bool asbdarkhatar = false, sarbaz1darkhatar = false, sarbaz2darkhatar = false, vazirdarkhatar = false;//doroste ghesmati braye farar mohreha dashtim ama darsoorti ke harekat sade amn nadashte bashn mian inja ta vazir mohafezeshun she
			int jahatmohreasb = 0, jahatmohresarbaz1 = 0, jahatmohresarbaz2 = 0;
			int jahathayemojaz[8] = { 0 };
			int shomarande = 0;
			int meghdarharekatsarbaz1[6] = { 0 }, meghdarharekatsarbaz2[6] = { 0 }, meghdarharekatasb[6] = { 0 }, meghdarharekatvazir[6] = { 0 };
			search_mohre_darkhatar(setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, vazirmojood, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2sotoon, sarbaz1nam, sarbaz2satr, sarbaz2nam, vazirsatr, vazirsotoon, asbnam, vazirnammm, &sarbaz1darkhatar, &sarbaz2darkhatar, &asbdarkhatar, &vazirdarkhatar);

			if (asbdarkhatar == true && yekharekat == false)
			{
				sarbaz1mohafezeshe = false, sarbaz2mohafezeshe = false, vazirmohafezeshe = false, asbmohafezeshe = false;
				// asbdarkhatar = false, sarbaz1darkhatar = false, sarbaz2darkhatar = false, vazirdarkhatar = false;//doroste ghesmati braye farar mohreha dashtim ama darsoorti ke harekat sade amn nadashte bashn mian inja ta vazir mohafezeshun she
				//int jahatmohreasb, jahatmohresarbaz1, jahatmohresarbaz2;
				//int jahathayemojaz[6] = { 0 };
				//int shomarande = 0;
				//int meghdarharekatsarbaz1[6] = { 0 }, meghdarharekatsarbaz2[6] = { 0 }, meghdarharekatasb[6] = { 0 }, meghdarharekatvazir[6] = { 0 };
				search_mohre_darkhatar(setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, vazirmojood, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2sotoon, sarbaz1nam, sarbaz2satr, sarbaz2nam, vazirsatr, vazirsotoon, asbnam, vazirnammm, &sarbaz1darkhatar, &sarbaz2darkhatar, &asbdarkhatar, &vazirdarkhatar);


				if (sarbaz1mojood)
					sarbaz1mohafezeshe = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbsatr, asbsotoon, map);
				if (sarbaz2mojood)
					sarbaz2mohafezeshe = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, map);

				if (vazirmojood)
					vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
				if ((sarbaz1mohafezeshe == true && sarbaz2mohafezeshe == false && vazirmohafezeshe == false) || (sarbaz2mohafezeshe == true && sarbaz1mohafezeshe == false && vazirmohafezeshe == false) || (vazirmohafezeshe == true && sarbaz1mohafezeshe == false && sarbaz2mohafezeshe == false) || (sarbaz1mohafezeshe == false && sarbaz2mohafezeshe == false && vazirmohafezeshe == false)) {

					shomarande = 0;
					mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
					vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon, asbnam);
					bool vazir_easy_go = false;
					//int countchandtameghdarsefre = 0, meghdarharekatasbok = 0;
					/////shomaresh tedad anasor jahathaye mojaz
					for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
						//	cout << "\nshomarande:" << shomarande << endl;
						if (meghdarharekatasb[shomarande] == 0)
							continue;
						//	bool vazir_easy_for_khatar(int jahat, int vazirsatr, int vazirsotoon, char sarnam, int meghdarharekat, char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon)
						/*if (meghdarharekatasb[shomarande] == 0) {
						countchandtameghdarsefre += 1;
						if (countchandtameghdarsefre > 4)
						meghdarharekatasbok = 1;
						else
						continue;
						}
						*/
						/////////////////////////part3
						//aya_zadan_ghable_farar_amn_ast(harifsatr, int harifsotoon, char setplayer, int mohafezchist, int satrmohrekhodi, int sotoonmohrekhodi, char map[6][6], char copyofmap1[6][6], char nammohre)

						vazir_easy_go = vazir_easy_for_khatar(asbsatr, asbsotoon, khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasb[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
						if (vazir_easy_go == true)
						{
							edamebadekhatar = false;
							yekharekat = true;
							easyallow = false;
							break;
						}
					}
					/*if (countchandtameghdarsefre > 4) {

					for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
					{
					vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasbok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

					if (vazir_easy_go)
					{
					yekharekat = true;
					break;
					}
					else
					continue;
					}
					//}*/
					////////////part2
				}
			}
		}
	}

	////////////////////////////////////////////////////////////

	////////////////////////////////


	//////////////////zarb vazir//////////////////////
	if (easyallow = true && yekharekat == false) {

		if (setplayer == '1')
		{
			if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
				satrsarbazjadid = 0;
				sotoonsarbazjadid = 0;
				bool sarbaz1_trial = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[0], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);


				sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[0], map, khodi, 0, 0, false);

			}


			if (sarbaz1) {

				//		cout << "sarbaz1barghararast";
				easyallow = false;
				yekharekat = true;

			}
			if (!sarbaz1&&sarbaz2mojood == true) {

				if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
					satrsarbazjadid = 0;
					sotoonsarbazjadid = 0;
					bool sarbaz2_trial = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[0], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
					sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[0], map, khodi, 0, 0, false);


				}
			}
			if (sarbaz2) {

				//	cout << "sarbaz2 barghararast";
				//	cout << sarbaz2satr;
				easyallow = false;
				yekharekat = true;

			}
		}
		else
		{
			if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
				satrsarbazjadid = 0;
				sotoonsarbazjadid = 0;
				bool sarbaz1_trial = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[0], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);

				sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[0], map, khodi, 0, 0, false);

			}
			if (sarbaz1) {
				//		cout << "sarbaz1barghararast";
				easyallow = false;
				yekharekat = true;

			}
			if (!sarbaz1&&sarbaz2mojood == true) {
				if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
					satrsarbazjadid = 0;
					sotoonsarbazjadid = 0;
					bool sarbaz2_trial = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[0], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);

					sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[0], map, khodi, 0, 0, false);

				}

			}
		}
		if (sarbaz2) {
			//	cout << "sarbaz2 barghararast";
			//	cout << sarbaz2satr;
			easyallow = false;
			yekharekat = true;

		}



		if (!sarbaz2&&asbmojood == true) {
			if (asbsatr >= 0 && asbsotoon >= 0) {

				bool asb_trial = zarbasb(asbsatr, asbsotoon, asbnam, costn[0], map, khodi, &satrasbjadid, &sotoonasbjadid, true);
				asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[0], map, khodi, 0, 0, false);


			}
		}

		if (asb) {
			//	cout << "asb";
			easyallow = false;
			yekharekat = true;

		}

		if (!asb) {

			//	cin >> satr;
			int satrvazirjadid = -1, sotoonvazirjadid = -1;
			//cout << "asb nist";
			//cout << "s" << asbsatr << asbsotoon;
			//	int a;
			//cin >> a;

			if (vazirsatr >= 0 && vazirsotoon >= 0 && vazirmojood == true) {
				bool vazir_trial = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[0], map, khodi, &satrvazirjadid, &sotoonvazirjadid, true);
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrvazirjadid, sotoonvazirjadid);
				//cout << satrvazirjadid << sotoonvazirjadid;
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[0], map, khodi, 0, 0, false);
				}//if trueha
				else
				{
					if (sarbaz1mojood)
					{
						bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map);
						if (mohafezsarbaz1 == true) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, vazirsatr, vazirsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
								sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
								, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
								vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[0], map, khodi, 0, 0, false);
							}
						}//if sarbaz1mojood
					}
					if (sarbaz2mojood)
					{
						bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map);
						if (mohafezsarbaz2) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, vazirsatr, vazirsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
								sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
								, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
								vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[0], map, khodi, 0, 0, false);
							}
						}
					}
					if (asbmojood)
					{
						bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map);
						if (mohafezasb) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, vazirsatr, vazirsotoon, setplayer, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
								sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
								, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
								vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[0], map, khodi, 0, 0, false);
							}
						}
					}
				}//else trueha



			}
		}
	}
	///////////////////etmam zarb vazir//////////////////////
	///////////////////zarb asb/////////////////////////////
	//sarbaza darharsharayeti bezane asbo asbam ba mohafezat bezane vaziram tebgh for ba mohafezat bezane
	if (easyallow = true && yekharekat == false) {

		if (setplayer == '1')
		{

			if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
				satrsarbazjadid = 0;
				sotoonsarbazjadid = 0;
				bool sarbaz1_trial = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[1], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
				if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))
					sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[1], map, khodi, 0, 0, false);

			}

			if (sarbaz1) {

				//		cout << "sarbaz1barghararast";
				easyallow = false;
				yekharekat = true;
			}
			if (!sarbaz1&&sarbaz2mojood == true) {

				if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
					satrsarbazjadid = 0;
					sotoonsarbazjadid = 0;
					bool sarbaz2_trial = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[1], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);

					if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

						sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[1], map, khodi, 0, 0, false);
				}//if trueha

			}
			if (sarbaz2) {

				//	cout << "sarbaz2 barghararast";
				//	cout << sarbaz2satr;
				easyallow = false;
				yekharekat = true;
			}
		}

		else
		{
			if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
				satrsarbazjadid = -1;
				sotoonsarbazjadid = -1;
				bool sarbaz1_trial = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[1], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);

				sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[1], map, khodi, 0, 0, false);

			}
			if (sarbaz1) {
				//		cout << "sarbaz1barghararast";
				easyallow = false;
				yekharekat = true;

			}
			if (!sarbaz1&&sarbaz2mojood == true) {
				if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
					satrsarbazjadid = -1;
					sotoonsarbazjadid = -1;
					bool sarbaz2_trial = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[1], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
					if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

						sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[1], map, khodi, 0, 0, false);

				}

			}
			if (sarbaz2) {
				//	cout << "sarbaz2 barghararast";
				//	cout << sarbaz2satr;
				easyallow = false;
				yekharekat = true;

			}
		}


		if (!sarbaz2&&asbmojood == true) {
			if (asbsatr >= 0 && asbsotoon >= 0) {
				satrasbjadid = -1;
				sotoonasbjadid = -1;

				bool asb_trial = zarbasb(asbsatr, asbsotoon, asbnam, costn[1], map, khodi, &satrasbjadid, &sotoonasbjadid, true);
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrasbjadid, sotoonasbjadid);
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

						asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[1], map, khodi, 0, 0, false);

				}//if trueha
				else
				{
					if (sarbaz1mojood)
					{
						bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrasbjadid, sotoonasbjadid, map);
						if (mohafezsarbaz1) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, asbsatr, asbsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
								sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
								, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
								if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

									asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[1], map, khodi, 0, 0, false);
							}
						}
					}//if sarbaz1mojood
					if (sarbaz2mojood)
					{
						bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrasbjadid, sotoonasbjadid, map);
						if (mohafezsarbaz2 == true) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, asbsatr, asbsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
								sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
								, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
								if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

									asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[1], map, khodi, 0, 0, false);
							}
						}
					}
					if (vazirmojood)
					{
						bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrasbjadid, sotoonasbjadid, map);
						if (mohafezvazir == true) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, asbsatr, asbsotoon, setplayer, vazirsatr, vazirsotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
								sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
								, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
								if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))
									asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[1], map, khodi, 0, 0, false);
							}
						}
					}
				}//else trueha
			}
		}

		if (asb) {
			//	cout << "asb";
			easyallow = false;
			yekharekat = true;

		}
	}

	///////////////////////////////////////////////////////
	////////
	/*	if (easyallow == true && yekharekat == false) {
	///////////////////////////
	bool sarbaz1mohafezeshe=false, sarbaz2mohafezeshe=false, vazirmohafezeshe=false, asbmohafezeshe = false;
	bool asbdarkhatar = false, sarbaz1darkhatar = false, sarbaz2darkhatar = false, vazirdarkhatar = false;//doroste ghesmati braye farar mohreha dashtim ama darsoorti ke harekat sade amn nadashte bashn mian inja ta vazir mohafezeshun she
	int jahatmohreasb, jahatmohresarbaz1, jahatmohresarbaz2;
	int jahathayemojaz[6] = { 0 };
	int shomarande = 0;
	int meghdarharekatsarbaz1[6] = { 0 }, meghdarharekatsarbaz2[6] = { 0 }, meghdarharekatasb[6] = { 0 }, meghdarharekatvazir[6] = { 0 };
	search_mohre_darkhatar(setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, vazirmojood, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2sotoon, sarbaz1nam, sarbaz2satr, sarbaz2nam, vazirsatr, vazirsotoon, asbnam, vazirnammm, &sarbaz1darkhatar, &sarbaz2darkhatar, &asbdarkhatar, &vazirdarkhatar);
	if (vazirmojood) {

	if (asbdarkhatar&&sarbaz1darkhatar&&yekharekat == false)

	{//motegheyeraye esharegaro jadid kon baraharkodoom

	int meghdarforkhatar;
	int jahathayeasb[6] = { 0 }, jahathayesarbaz1[6] = { 0 };
	mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
	mohre_kojaye_vazire(&jahatmohresarbaz1, sarbaz1satr, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
	vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayeasb, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon);
	vazir_easy_easy(&jahatmohresarbaz1, vazirsatr, vazirsotoon, jahathayesarbaz1, meghdarharekatsarbaz1, khodicount, khodi, sarbaz1satr, sarbaz1sotoon);
	int vazirnewsatr = 0, vazirnewsotoon = 0;
	for (shomarande = 0; shomarande < sizeof jahathayeasb / sizeof(int); shomarande++) {
	if (yekharekat == true)
	break;

	for (int shomarandes1 = 0; shomarandes1 < sizeof jahathayesarbaz1 / sizeof(int); shomarandes1++)
	{

	if (jahathayeasb[shomarande] == jahathayesarbaz1[shomarandes1])
	{
	int jahatmoshtarak = jahathayeasb[shomarande];
	int meghdarharekatmoshtarak = meghdarharekatasb[shomarande];

	bool vazir_easy_go1 = vazir_easy(&meghdarforkhatar, setplayer, &jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);

	if (vazir_easy_go1 == true)
	{
	map[vazirnewsatr][vazirnewsotoon] = vazirnammm;
	map[vazirsatr][vazirsotoon] = '-';
	bool vazir_mitune_mohafez_asb = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, asbsatr, asbsotoon, map);
	bool vazir_mitune_mohafez_sarbaz = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, sarbaz2satr, sarbaz2sotoon, map);
	if (vazir_mitune_mohafez_asb == true && vazir_mitune_mohafez_sarbaz == true) {
	if (vazirharif)
	canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, 'v');
	if (asbharif)
	canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
	if (canescapefromasb == true && canescapefromvazir == true) {

	bool vazir_easy_go2 = vazir_easy_for_khatar(khodi, jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, meghdarforkhatar, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
	if (vazir_easy_go2 == true) {
	yekharekat = true;
	easyallow = false;

	}
	else {
	map[vazirnewsatr][vazirnewsotoon] = '-';
	map[vazirsatr][vazirsotoon] = vazirnammm;
	}
	//	if(mohafez_darad(setplayer,'v',vazirsatr,vazirsotoon
	}
	else {
	map[vazirnewsatr][vazirnewsotoon] = '-';
	map[vazirsatr][vazirsotoon] = vazirnammm;
	}

	}
	else {
	map[vazirnewsatr][vazirnewsotoon] = '-';
	map[vazirsatr][vazirsotoon] = vazirnammm;
	}
	}
	else
	continue;
	}
	}
	}

	}
	if (asbdarkhatar&&sarbaz2darkhatar&&yekharekat == false)

	{//motegheyeraye esharegaro jadid kon baraharkodoom

	int meghdarforkhatar;
	int jahathayeasb[6] = { 0 }, jahathayesarbaz2[6] = { 0 };
	mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
	mohre_kojaye_vazire(&jahatmohresarbaz2, sarbaz2satr, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
	vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayeasb, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon);
	vazir_easy_easy(&jahatmohresarbaz2, vazirsatr, vazirsotoon, jahathayesarbaz2, meghdarharekatsarbaz2, khodicount, khodi, sarbaz2satr, sarbaz2sotoon);
	int vazirnewsatr = 0, vazirnewsotoon = 0;

	for (shomarande = 0; shomarande < sizeof jahathayeasb[shomarande] / sizeof(int); shomarande++) {
	if (yekharekat == true)
	break;
	if ((sarbaz1mohafezeshe == true && sarbaz2mohafezeshe == false && vazirmohafezeshe == false) || (sarbaz2mohafezeshe == true && sarbaz1mohafezeshe == false && vazirmohafezeshe == false) || (vazirmohafezeshe == true && sarbaz1mohafezeshe == false && sarbaz2mohafezeshe == false) || (sarbaz1mohafezeshe == false && sarbaz2mohafezeshe == false && vazirmohafezeshe == false)) {

	for (int shomarandes1 = 0; shomarandes1 < sizeof jahathayesarbaz2 / sizeof(int); shomarandes1++)
	{

	if (jahathayeasb[shomarande] == jahathayesarbaz2[shomarandes1])
	{
	int jahatmoshtarak = jahathayeasb[shomarande];
	int meghdarharekatmoshtarak = meghdarharekatasb[shomarande];
	bool vazir_easy_go1 = vazir_easy(&meghdarforkhatar, setplayer, &jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);

	if (vazir_easy_go1 == true)
	{
	map[vazirnewsatr][vazirnewsotoon] = vazirnammm;
	map[vazirsatr][vazirsotoon] = '-';
	bool vazir_mitune_mohafez_asb = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, asbsatr, asbsotoon, map);
	bool vazir_mitune_mohafez_sarbaz = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, sarbaz2satr, sarbaz2sotoon, map);
	if (vazir_mitune_mohafez_asb == true && vazir_mitune_mohafez_sarbaz == true) {
	if (vazirharif)
	canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, 'v');
	if (asbharif)
	canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
	if (canescapefromasb == true && canescapefromvazir == true) {

	bool vazir_easy_go2 = vazir_easy_for_khatar(khodi, jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, meghdarforkhatar, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
	if (vazir_easy_go2) {
	yekharekat = true;
	easyallow = false;
	break;
	}
	else {
	map[vazirnewsatr][vazirnewsotoon] = '-';
	map[vazirsatr][vazirsotoon] = vazirnammm;
	}
	//	if(mohafez_darad(setplayer,'v',vazirsatr,vazirsotoon
	}
	else {
	map[vazirnewsatr][vazirnewsotoon] = '-';
	map[vazirsatr][vazirsotoon] = vazirnammm;
	}

	}
	else {
	map[vazirnewsatr][vazirnewsotoon] = '-';
	map[vazirsatr][vazirsotoon] = vazirnammm;
	}
	}
	else
	continue;

	}
	}
	}
	}

	}
	if (asbdarkhatar == true && yekharekat == false)
	{

	if (sarbaz1mojood)
	sarbaz1mohafezeshe = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbsatr, asbsotoon, map);
	if (sarbaz2mojood)
	sarbaz2mohafezeshe = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, map);

	if (vazirmojood)
	vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
	if ( (sarbaz1mohafezeshe == true && sarbaz2mohafezeshe == false && vazirmohafezeshe == false) || (sarbaz2mohafezeshe==true&&sarbaz1mohafezeshe==false&&vazirmohafezeshe==false) ||(vazirmohafezeshe==true&&sarbaz1mohafezeshe==false&&sarbaz2mohafezeshe==false)||(sarbaz1mohafezeshe==false&&sarbaz2mohafezeshe==false&&vazirmohafezeshe==false) ) {

	shomarande = 0;
	mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
	vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon);
	bool vazir_easy_go = false;
	//int countchandtameghdarsefre = 0, meghdarharekatasbok = 0;
	/////shomaresh tedad anasor jahathaye mojaz
	for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
	cout << "\nshomarande:" << shomarande << endl;
	if (meghdarharekatasb[shomarande] == 0)
	continue;
	//	bool vazir_easy_for_khatar(int jahat, int vazirsatr, int vazirsotoon, char sarnam, int meghdarharekat, char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon)
	/*if (meghdarharekatasb[shomarande] == 0) {
	countchandtameghdarsefre += 1;
	if (countchandtameghdarsefre > 4)
	meghdarharekatasbok = 1;
	else
	continue;
	}
	*/
	/////////////////////////part3
	/*
	vazir_easy_go = vazir_easy_for_khatar(khodi, jahatmohreasb, vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasb[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
	if (vazir_easy_go == true)
	{
	yekharekat = true;
	easyallow = false;
	break;
	}
	}
	/*if (countchandtameghdarsefre > 4) {

	for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
	{
	vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasbok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

	if (vazir_easy_go)
	{
	yekharekat = true;
	break;
	}
	else
	continue;
	}
	//}*/
	////////////part2
	/*}
	}
	if (sarbaz1darkhatar == true && yekharekat == false)
	{
	if (sarbaz2mojood)
	sarbaz2mohafezeshe = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
	if (asbmojood)
	asbmohafezeshe = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr, sarbaz1sotoon, map);
	if (vazirmojood)
	vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr, sarbaz1sotoon, map);
	//if (sarbaz2mohafezeshe == false && asbmohafezeshe == false && vazirmohafezeshe == false) {
	if ((sarbaz1mohafezeshe == true && vazirmohafezeshe == false && asbmohafezeshe == false) || (vazirmohafezeshe == true && sarbaz1mohafezeshe == false && asbmohafezeshe == false) || (asbmohafezeshe == true && vazirmohafezeshe == false && sarbaz1mohafezeshe == false)||(vazirmohafezeshe==false&&asbmohafezeshe==false&&sarbaz2mohafezeshe==false)) {

	shomarande = 0;
	cout << sarbaz1satr << sarbaz1sotoon;

	mohre_kojaye_vazire(&jahatmohresarbaz1, sarbaz1satr, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
	vazir_easy_easy(&jahatmohresarbaz1, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatsarbaz1, khodicount, khodi, sarbaz1satr, sarbaz1sotoon);
	bool aya_vazir_mohafez_asb = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
	//if (aya_vazir_mohafez_asb == false) {
	bool vazir_easy_go = false;
	/////shomaresh tedad anasor jahathaye mojaz
	int countchandtameghdarsefre = 0;
	int meghdarharekatsarbaz1ok = 0;
	for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
	if (meghdarharekatsarbaz1[shomarande] == 0) {
	countchandtameghdarsefre += 1;
	if (countchandtameghdarsefre > 4)
	meghdarharekatsarbaz1ok = 1;
	else
	continue;
	}

	vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz1[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

	if (vazir_easy_go)
	{
	yekharekat = true;
	easyallow = false;
	break;

	}
	else
	continue;
	}

	if (countchandtameghdarsefre > 4) {

	for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
	{
	vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz1ok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

	if (vazir_easy_go)
	{
	yekharekat = true;
	easyallow = false;
	break;
	}
	else
	continue;
	}


	}

	//}
	}
	}
	if (sarbaz2darkhatar == true && yekharekat == false)
	{

	if (sarbaz1mojood)
	sarbaz1mohafezeshe = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
	if (asbmojood)
	asbmohafezeshe = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr, sarbaz2sotoon, map);
	if (vazirmojood)
	vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr, sarbaz2sotoon, map);
	//if (sarbaz1mohafezeshe == false && asbmohafezeshe == false && vazirmohafezeshe == false) {
	if( (sarbaz1mohafezeshe==true&&vazirmohafezeshe==false&&asbmohafezeshe==false) || (vazirmohafezeshe==true&&sarbaz1mohafezeshe==false&&asbmohafezeshe==false )|| (asbmohafezeshe==true&&vazirmohafezeshe==false&&sarbaz1mohafezeshe==false||(vazirmohafezeshe == false && asbmohafezeshe == false && sarbaz2mohafezeshe == false)) ){
	int countchandtameghdarsefre = 0, meghdarharekatsarbaz2ok = 1;
	shomarande = 0;
	mohre_kojaye_vazire(&jahatmohresarbaz2, sarbaz2satr, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
	vazir_easy_easy(&jahatmohresarbaz2, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatsarbaz2, khodicount, khodi, sarbaz2satr, sarbaz2sotoon);

	bool aya_vazir_mohafez_asb = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
	if (aya_vazir_mohafez_asb == false) {
	bool vazir_easy_go = false;

	/////shomaresh tedad anasor jahathaye mojaz
	for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
	if (meghdarharekatsarbaz2[shomarande] == 0) {
	countchandtameghdarsefre += 1;
	if (countchandtameghdarsefre > 4)
	meghdarharekatsarbaz2ok = 1;
	else
	continue;
	}
	vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz2[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

	if (vazir_easy_go)
	{

	yekharekat = true;
	easyallow = false;
	break;
	}
	}

	if (countchandtameghdarsefre > 4) {

	for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
	{
	vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz2ok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

	if (vazir_easy_go)
	{
	yekharekat = true;
	easyallow = false;
	break;
	}
	else
	continue;
	}
	}
	}
	}
	}
	}


	}	//ifvazirmojood


	*/
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (easyallow == true && asbmojood == true) {

		int countasbzarbpazir = 0, tedadmohafezasb = 0;
		//اينو گذاشتم تا همون اول بازي ببينه وزيرجاي خطرناکي هست يا نه اگه بود سريعا با يه حرکت ساده جاش عوض شه
		int asbnewsatr = 0, asbnewsotoon = 0;
		bool mohafezvazir = false;
		//1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
		bool asbeasyy;
		int jahatasb = 1;
		if (sarbaz1harif)
			cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbsatr, asbsotoon, map, asbnam);
		if (sarbaz2harif)
			cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbsatr, asbsotoon, map, asbnam);
		if (asbharif)
			cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, asbsatr, asbsotoon);
		if (vazirharif)
			cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map, asbnam);
		if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false) {

			bool asbmohafezavvaldarad = false;
			if (sarbaz1mojood)
			{
				bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbsatr, asbsotoon, map);
				if (mohafezsarbaz1)
					asbmohafezavvaldarad = true;
			}//if sarbaz1mojood
			if (sarbaz2mojood)
			{
				bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, map);
				if (mohafezsarbaz2)
					asbmohafezavvaldarad = true;
			}
			if (vazirmojood)
			{
				mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
				if (mohafezvazir)
					asbmohafezavvaldarad = true;
			}
			// گفتیم حریفی ک تهدیدت میکنه سرباز بود دیگه روی محافظت حساب باز نکن
			//مگر اینکه محافظت وزیر باشه
			if (mohafezvazir == false && (cangofromsarbaz1 == false || cangofromsarbaz2 == false))
				asbmohafezavvaldarad = false;
			bool harekatzarbidare = false;
			if (asbmohafezavvaldarad == false) {

				bool can_zarb_vazir = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, vazirharifsatr, vazirharifsotoon, map);
				if (can_zarb_vazir == true)
				{
					char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
					aya_zadan_ghable_farar_amn_ast(vazirharifsatr, vazirharifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
					bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirharifsatr, vazirharifsotoon, copyofmap1, asbnam);
					bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirharifsatr, vazirharifsotoon, copyofmap1, asbnam);
					bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon);
					if (_cangofromsarbaz1 == true && _cangofromsarbaz2 == true && _cangofromasb == true)
					{
						harekatzarbidare = true;
					}
				}
				////////////
				////
				bool can_zarb_asb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, asbharifsatr, asbharifsotoon, map);
				if (can_zarb_asb == true)
				{
					char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
					aya_zadan_ghable_farar_amn_ast(asbharifsatr, asbharifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
					bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
					bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
					bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
					if (_cangofromsarbaz1 == true && _cangofromsarbaz2 == true && _cangofromvazir == true)
					{
						harekatzarbidare = true;
					}
				}
				///////////////////
				bool can_zarb_sarbaz1 = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map);
				if (can_zarb_sarbaz1 == true)
				{
					char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
					aya_zadan_ghable_farar_amn_ast(sarbaz1harifsatr, sarbaz1harifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
					//	bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbharifsatr, asbharifsotoon, copyofmap1, asbnam);
					bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
					bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon);
					bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
					if (_cangofromvazir == true && _cangofromsarbaz2 == true && _cangofromasb == true)
					{
						harekatzarbidare = true;
					}
				}
				////////////////////////
				bool can_zarb_sarbaz2 = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, map);
				if (can_zarb_sarbaz2 == true)
				{
					char copyofmap1[6][6];//araye ba ravesh erja mire hamin tabe paeino ejra koni khode tabe poresh mikone
					aya_zadan_ghable_farar_amn_ast(sarbaz2harifsatr, sarbaz2harifsotoon, setplayer, 2, asbsatr, asbsotoon, map, copyofmap1, asbnam);
					bool _cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, copyofmap1, asbnam);
					//	bool _cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, copyofmap1, asbnam);
					bool _cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon);
					bool _cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, copyofmap1, asbnam);
					if (_cangofromvazir == true && _cangofromsarbaz1 == true && _cangofromasb == true)
					{
						harekatzarbidare = true;
					}
				}
				////////////////////
				//حالا یکاری میکنیم ک اگه اسب درخطر بود و میتونه با امنیت مهره ای رو بزنه  دیگه فرارش کار نکنه و ضربی عمل کنه
				///
				if (harekatzarbidare == false) {

					for (int jahatasb2 = 0; jahatasb2 < 8; jahatasb2++) {
						asbeasyy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, true);
						//bool vazir_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* khatar, int* meghdarharekati = 0, bool khataryab = false)
						//بيايم بگيم  يه جهت  ساده تو قسمت ايزي الو تعريف کنيم
						//بعد بعد چک کردن 4 کن گو و ايف اصلي بگيم اگه ايف نقض شد
						//تو السش اول جهت يکي اضافه بشه بعد دوباره وزير فور ايزي اجرا ببشه
						//تا زماني ک ايف اصليمون (4تا شرطه)ترو بشه
						//براي بقيه مهرهام همينکارو بکن

						//	cout << "\nasbNew" << jahatasb;
						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
						if (cangofromsarbaz1 == false)
							countasbzarbpazir += 1;
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
						if (cangofromsarbaz2 == false)
							countasbzarbpazir += 1;
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, asbnewsatr, asbnewsotoon);
						if (cangofromasb == false)
							countasbzarbpazir += 1;
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
						if (cangofromvazir == false)
							countasbzarbpazir += 1;

						//						cout << cangofromasb;//5 mide
						//cin >> khatar;
						if (asbeasyy == true && cangofromvazir == false || cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false)
						{
							bool asbmohafezdarad = false;
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbnewsatr, asbnewsotoon, map);
								if (mohafezsarbaz1 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, asbsatr, asbsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										asbmohafezdarad = true;
										tedadmohafezasb += 1;
									}
								}
							}//if sarbaz1mojood
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbnewsatr, asbnewsotoon, map);
								if (mohafezsarbaz2 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, asbsatr, asbsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										asbmohafezdarad = true;
										tedadmohafezasb += 1;
									}
								}
							}
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbnewsatr, asbnewsotoon, map);
								if (mohafezvazir == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, asbsatr, asbsotoon, setplayer, vazirsatr, vazirsotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										asbmohafezdarad = true;
										tedadmohafezasb += 1;
									}
								}
							}
							if (asbmohafezdarad == true && tedadmohafezasb >= countasbzarbpazir)
							{
								bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								if (vazirdarkhatarast == false) {
									asbforeasy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, false);
									if (asbforeasy) {
										easyallow = false;
										edamebadekhatar = false;
										yekharekat = true;
										break;
									}
								}
							}

						}
						if (asbeasyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {

							bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
							if (vazirdarkhatarast == false) {

								asbforeasy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, false);
								bool 	asbgo = true;
								if (asbforeasy) {
									easyallow = false;
									edamebadekhatar = false;
									yekharekat = true;
									break;
								}
							}
						}
						else {
							//if (jahatvazir == 8)
							//vazirforeasy = false;
							//	cout << "else shod";
							jahatasb++;
							//							vazirforeasy = false;
						}

					}//forjahatvazir
				}
			}
		}
	}//ifasbmojood

	int s1counter = 0, s2counter = 0;

	if (easyallow == true && sarbaz1mojood)
	{

		if (sarbaz1harif)
			cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz1satr, sarbaz1sotoon, map, sarbaz1nam);
		if (sarbaz2harif)
			cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1satr, sarbaz1sotoon, map, sarbaz1nam);
		if (asbharif)
			cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr, sarbaz1sotoon);
		if (vazirharif)
			cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, map, sarbaz1nam);
		bool sarbaz1mohafezavvaldarad = false;
		if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
		{
			//ما اومديم اول گفتيم ببينيم سرباز محافظ داره يانه اگه داشت ديگه تکونش نديم پس اول اطلاعات خودشو ميديم نه محل جديدشو

			if (sarbaz2mojood)
			{
				bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
				if (mohafezsarbaz)
					sarbaz1mohafezavvaldarad = true;
			}//if sarbaz2mojood
			if (asbmojood)
			{
				bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr, sarbaz1sotoon, map);
				if (mohafezasb)
					sarbaz1mohafezavvaldarad = true;
			}//if asbmojood
			if (vazirmojood)
			{
				bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr, sarbaz1sotoon, map);
				if (mohafezvazir)
					sarbaz1mohafezavvaldarad = true;

			}
			int countsarbaz1zarbpazir = 0, tedadmohafezsarbaz1 = 0;
			if (sarbaz1mohafezavvaldarad == false) {
				if (setplayer == '1')
				{

					sarbazz_can_move = sarbaz_can_move(setplayer, sarbaz1satr, sarbaz1sotoon, map);
					if (sarbazz_can_move == true) {
						//همون اول بگو اگه سطربه اضافه يک 6در6 نقض ميکنه ديگه ادمه نده
						if (sarbaz1satr + 1 <= 5) {
							if (sarbaz1satr <= 5 && sarbaz1sotoon <= 5) {
								if (s1counter > 25)
									sarbaz1foreasy = false;
								if (sarbaz1harif)
									cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
								if (cangofromsarbaz1 == false)
									countsarbaz1zarbpazir += 1;
								if (sarbaz2harif)
									cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
								if (cangofromsarbaz2 == false)
									countsarbaz1zarbpazir += 1;
								if (asbharif)
									cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr + 1, sarbaz1sotoon);
								if (cangofromasb == false)
									countsarbaz1zarbpazir += 1;
								if (vazirharif)
									cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
								if (cangofromvazir == false)
									countsarbaz1zarbpazir += 1;

								if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
								{
									bool sarbaz1mohafezdovvomdarad = false;
									if (sarbaz2mojood)
									{
										bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
										if (mohafezsarbaz == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz1mohafezdovvomdarad = true;

												tedadmohafezsarbaz1 += 1;
											}
										}
									}//if sarbaz2mojood
									if (asbmojood)
									{
										bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
										if (mohafezasb == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz1mohafezdovvomdarad = true;


												tedadmohafezsarbaz1 += 1;
											}
										}
									}//if asbmojood

									if (vazirmojood)
									{
										bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
										if (mohafezvazir == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz1mohafezdovvomdarad = true;

												tedadmohafezsarbaz1 += 1;
											}
										}
									}
									if (sarbaz1mohafezdovvomdarad == true && tedadmohafezsarbaz1 >= countsarbaz1zarbpazir)
									{
										bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
										bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
										if (vazirdarkhatarast == false && asbdarkhatarast == false) {
											sarbaz1foreasy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
											if (sarbaz1foreasy) {
												easyallow = false;
												edamebadekhatar = false;
											}
											if (!sarbaz1foreasy)
												easyallow = true;
										}
									}

								}


								if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
									bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										sarbaz1foreasy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
										if (sarbaz1foreasy) {
											easyallow = false;
											edamebadekhatar = false;
										}
										if (!sarbaz1foreasy)
											easyallow = true;
									}
								}
							}
						}
					}
				}

				else {
					if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0) {
						if (s1counter > 25)
							sarbaz1foreasy = false;
						if (sarbaz1satr - 1 >= 0) {

							if (sarbaz1harif)
								cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, (sarbaz1satr - 1), sarbaz1sotoon, map, sarbaz1nam);
							if (cangofromsarbaz1 == false)
								countsarbaz1zarbpazir += 1;
							if (sarbaz2harif)
								cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, (sarbaz1satr - 1), sarbaz1sotoon, map, sarbaz1nam);
							if (cangofromsarbaz2 == false)
								countsarbaz1zarbpazir += 1;
							if (asbharif)
								cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr - 1, sarbaz1sotoon);
							if (cangofromasb == false)
								countsarbaz1zarbpazir += 1;
							if (vazirharif)
								cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1nam);
							if (cangofromvazir == false)
								countsarbaz1zarbpazir += 1;
							if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
							{
								bool sarbaz1mohafezdovvomdarad = false;
								if (sarbaz2mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
									if (mohafezsarbaz == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											sarbaz1mohafezdovvomdarad = true;

											tedadmohafezsarbaz1 += 1;
										}
									}
								}//if sarbaz2mojood
								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
									if (mohafezasb) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											sarbaz1mohafezdovvomdarad = true;

											tedadmohafezsarbaz1 += 1;
										}
									}
								}//if asbmojood
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
									if (mohafezvazir == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											sarbaz1mohafezdovvomdarad = true;

											tedadmohafezsarbaz1 += 1;
										}
									}
								}
								if (sarbaz1mohafezdovvomdarad&&tedadmohafezsarbaz1 >= countsarbaz1zarbpazir)
								{
									bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										sarbaz1foreasy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
										if (sarbaz1foreasy) {
											easyallow = false;
											edamebadekhatar = false;
										}
										if (!sarbaz1foreasy)
											easyallow = true;
									}
								}

							}


							if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
								bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false && asbdarkhatarast == false) {
									sarbaz1foreasy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
									if (sarbaz1foreasy) {
										easyallow = false;

										edamebadekhatar = false;
									}
									if (!sarbaz1foreasy)
										easyallow = true;
								}
							}
						}
					}
				}

			}
		}
	}//if falsa

	if (easyallow == true && sarbaz2mojood)
	{
		//cout << edamebadekhatar;
		int tedadmohafezsarbaz2 = 0, countsarbaz2zarbpazir = 0;
		//اين فقط چک ميکنه اگه سرباز دو درخطر بود حالا بيا چک کن محافظ داره يا نه اگه محافظ نداشت يه حرکت ساده بده محافظ داره يا نه و ....
		if (sarbaz1harif)
			cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr, sarbaz2sotoon, map, sarbaz2nam);

		if (sarbaz2harif)
			cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr, sarbaz2sotoon, map, sarbaz2nam);

		if (asbharif)
			cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr, sarbaz2sotoon);

		if (vazirharif)
			cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr, sarbaz2sotoon, map, sarbaz2nam);
		bool sarbaz2mohafezavvaldarad = false;
		if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
		{



			//ما اومديم اول گفتيم ببينيم سرباز محافظ داره يانه اگه داشت ديگه تکونش نديم پس اول اطلاعات خودشو ميديم نه محل جديدشو

			if (sarbaz1mojood)
			{
				bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
				if (mohafezsarbaz)
					sarbaz2mohafezavvaldarad = true;
			}//if sarbaz2mojood
			if (asbmojood)
			{
				bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr, sarbaz2sotoon, map);
				if (mohafezasb)
					sarbaz2mohafezavvaldarad = true;
			}//if asbmojood
			if (vazirmojood)
			{
				bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr, sarbaz2sotoon, map);
				if (mohafezvazir)
					sarbaz2mohafezavvaldarad = true;
			}

			if (sarbaz2mohafezavvaldarad == false) {//akharesho radif kon

				sarbazz_can_move = sarbaz_can_move(setplayer, sarbaz1satr, sarbaz1sotoon, map);
				if (sarbazz_can_move == true) {
					if (setplayer == '1')
					{
						if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
							if (s2counter > 25)
								sarbaz2foreasy = false;
							if (sarbaz2satr + 1 <= 5) {
								if (sarbaz1harif)
									cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
								if (cangofromsarbaz1 == false)
									countsarbaz2zarbpazir += 1;
								if (sarbaz2harif)
									cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
								if (cangofromsarbaz2 == false)
									countsarbaz2zarbpazir += 1;
								if (asbharif)
									cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr + 1, sarbaz2sotoon);
								if (cangofromasb == false)
									countsarbaz2zarbpazir += 1;
								if (vazirharif)
									cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
								if (cangofromvazir == false)
									countsarbaz2zarbpazir += 1;
								if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
								{
									bool sarbaz2mohafezdovvomdarad = false;
									if (sarbaz1mojood)
									{
										bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
										if (mohafezsarbaz == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz2mohafezdovvomdarad = true;

												tedadmohafezsarbaz2 += 1;
											}
										}
									}//if sarbaz2mojood
									if (asbmojood)
									{
										bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
										if (mohafezasb == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz2mohafezdovvomdarad = true;

												tedadmohafezsarbaz2 += 1;
											}
										}
									}//if asbmojood
									if (vazirmojood)
									{
										bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
										if (mohafezvazir == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz2mohafezdovvomdarad = true;

												tedadmohafezsarbaz2 += 1;
											}
										}
									}
									if (sarbaz2mohafezdovvomdarad&&tedadmohafezsarbaz2 >= countsarbaz2zarbpazir)
									{
										bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
										bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
										if (vazirdarkhatarast == false && asbdarkhatarast == false) {
											sarbaz2foreasy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
											if (sarbaz2foreasy) {
												easyallow = false;
												edamebadekhatar = false;
											}
											if (!sarbaz2foreasy)
												easyallow = true;
										}
									}

								}


								if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
									bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										sarbaz1foreasy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
										if (sarbaz1foreasy) {
											easyallow = false;
											edamebadekhatar = false;
										}
										if (!sarbaz1foreasy)
											easyallow = true;
									}
								}
							}
						}
					}
					else {
						if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0) {
							if (sarbaz2satr - 1 >= 0) {
								if (sarbaz1harif)
									cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, (sarbaz2satr - 1), sarbaz2sotoon, map, sarbaz2nam);
								if (cangofromsarbaz1 == false)
									countsarbaz2zarbpazir += 1;
								if (sarbaz2harif)
									cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, (sarbaz2satr - 1), sarbaz2sotoon, map, sarbaz2nam);
								if (cangofromsarbaz2 == false)
									countsarbaz2zarbpazir += 1;
								if (asbharif)
									cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr - 1, sarbaz2sotoon);
								if (cangofromasb == false)
									countsarbaz2zarbpazir += 1;
								if (vazirharif)
									cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
								if (cangofromvazir == false)
									countsarbaz2zarbpazir += 1;
								if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
								{
									bool sarbaz2mohafezdovvomdarad = false;
									if (sarbaz1mojood)
									{
										bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
										if (mohafezsarbaz == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz2mohafezdovvomdarad = true;

												tedadmohafezsarbaz2 += 1;
											}
										}//if sarbaz2mojood
									}
									if (asbmojood)
									{
										bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
										if (mohafezasb == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz2mohafezdovvomdarad = true;

												tedadmohafezsarbaz2 += 1;
											}
										}
									}//if asbmojood
									if (vazirmojood)
									{
										bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
										if (mohafezvazir == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												sarbaz2mohafezdovvomdarad = true;

												tedadmohafezsarbaz2 += 1;
											}
										}
									}
									if (sarbaz2mohafezdovvomdarad&&tedadmohafezsarbaz2 >= countsarbaz2zarbpazir)
									{
										bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
										bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
										if (vazirdarkhatarast == false && asbdarkhatarast == false) {
											sarbaz2foreasy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
											if (sarbaz2foreasy) {
												easyallow = false;
												edamebadekhatar = false;
											}
											if (!sarbaz2foreasy)
												easyallow = true;
										}
									}

								}

								if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
									bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										sarbaz1foreasy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
										if (sarbaz1foreasy) {
											easyallow = false;
											edamebadekhatar = false;
										}
										if (!sarbaz1foreasy)
											easyallow = true;
									}
								}


							}
						}
					}
				}
			}//if falsa
		}
	}

	if (edamebadekhatar == true) {//
								  //cout << easyallow;
								  /////////////////////////////////////////////////
		for (int j = 0; j < 4; j++)//dasture breako yadet nare
		{                           //     baraye in comment kardam chon ma bayad satr o stoon khodi befrestim na harif
			if (cost[j] == 15)
			{
				continue;
				//		cout << "cost:" << cost[j] << "costn:" << costn[j] << endl;

			}

			if (cost[j] == 10)
			{
				//بگو اگه سربازا و اسب میتونستن اسبو بزنن درهرشرایطی بزننش
				//		cout << "cost:" << cost[j] << "costn:" << costn[j] << endl;


				if (!asb) {

					//	cin >> satr;
					int satrvazirjadid = -1, sotoonvazirjadid = -1;
					//cout << "asb nist";
					//cout << "s" << asbsatr << asbsotoon;
					//	int a;
					//cin >> a;

					if (vazirsatr >= 0 && vazirsotoon >= 0 && vazirmojood == true) {
						bool vazir_trial = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, &satrvazirjadid, &sotoonvazirjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrvazirjadid, sotoonvazirjadid);
						//cout << satrvazirjadid << sotoonvazirjadid;
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
						}//if trueha
						else
						{
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezsarbaz1 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, vazirsatr, vazirsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}//if sarbaz1mojood
							}
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezsarbaz2) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, vazirsatr, vazirsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezasb) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, vazirsatr, vazirsotoon, setplayer, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha

					}
				}
				if (vazir)
				{
					//cout << "okvazir";
					easyallow = false;
					yekharekat = true;
					break;
				}
				if (!vazir) {

					//	cout << " vaziram nist\n";
					continue;

				}
			}

			if (cost[j] == 5)
			{
				//		cout << "cost:" << cost[j] << "costn:" << costn[j] << endl;
				if (setplayer == '1')
				{
					if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
						satrsarbazjadid = 0;
						sotoonsarbazjadid = 0;
						bool sarbaz1_trial = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

								sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);

						}
						else
						{
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezsarbaz == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezasb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezvazir&&yekharekatmojazzarb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha
					}
					if (sarbaz1) {
						yekharekat = true;
						//		cout << "sarbaz1barghararast";
						easyallow = false;
						break;
					}
					if (!sarbaz1&&sarbaz2mojood == true) {

						if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
							satrsarbazjadid = 0;
							sotoonsarbazjadid = 0;
							bool sarbaz2_trial = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
							if (sarbaz1harif)
								canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (sarbaz2harif)
								canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (asbharif)
								canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
							if (vazirharif)
								canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
								if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

									sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
							}//if trueha
							else
							{
								if (sarbaz1mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezsarbaz == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}//if sarbaz2mojood
									}
								}
								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezasb == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}//if asbmojood
									}
								}
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezvazir == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}
							}//else trueha
						}
					}
					if (sarbaz2) {
						yekharekat = true;
						//	cout << "sarbaz2 barghararast";
						//	cout << sarbaz2satr;
						easyallow = false;
						break;
					}
				}

				else
				{
					if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
						satrsarbazjadid = -1;
						sotoonsarbazjadid = -1;
						bool sarbaz1_trial = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
						}//if trueha
						else
						{
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezsarbaz == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezasb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezvazir == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha
					}
					if (sarbaz1) {
						yekharekat = true;
						//		cout << "sarbaz1barghararast";
						easyallow = false;
						break;
					}
					if (!sarbaz1&&sarbaz2mojood == true) {
						if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
							satrsarbazjadid = -1;
							sotoonsarbazjadid = -1;
							bool sarbaz2_trial = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
							if (sarbaz1harif)
								canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (sarbaz2harif)
								canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (asbharif)
								canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
							if (vazirharif)
								canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
								if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

									sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);

							}
							else
							{
								if (sarbaz1mojood)
								{

									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezsarbaz == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}//if sarbaz2mojood

								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezasb == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}//if asbmojood
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezvazir == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}
							}//else trueha
						}
					}
					if (sarbaz2) {
						yekharekat = true;
						//	cout << "sarbaz2 barghararast";
						//	cout << sarbaz2satr;
						easyallow = false;
						break;
					}
				}


				if (!sarbaz2&&asbmojood == true) {
					if (asbsatr >= 0 && asbsotoon >= 0) {
						satrasbjadid = -1;
						sotoonasbjadid = -1;

						bool asb_trial = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, &satrasbjadid, &sotoonasbjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrasbjadid, sotoonasbjadid);
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

								asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);

						}//if trueha
						else
						{
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrasbjadid, sotoonasbjadid, map);
								if (mohafezsarbaz1) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, asbsatr, asbsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if sarbaz1mojood
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrasbjadid, sotoonasbjadid, map);
								if (mohafezsarbaz2 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, asbsatr, asbsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrasbjadid, sotoonasbjadid, map);
								if (mohafezvazir == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, asbsatr, asbsotoon, setplayer, vazirsatr, vazirsotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))
											asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha
					}
				}

				if (asb) {
					//	cout << "asb";
					easyallow = false;
					yekharekat = true;
					break;
				}

				if (!asb) {

					//	cin >> satr;
					int satrvazirjadid = -1, sotoonvazirjadid = -1;
					//cout << "asb nist";
					//cout << "s" << asbsatr << asbsotoon;
					//	int a;
					//cin >> a;

					if (vazirsatr >= 0 && vazirsotoon >= 0 && vazirmojood == true) {
						bool vazir_trial = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, &satrvazirjadid, &sotoonvazirjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrvazirjadid, sotoonvazirjadid);
						//cout << satrvazirjadid << sotoonvazirjadid;
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
						}//if trueha
						else
						{
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezsarbaz1 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, vazirsatr, vazirsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}//if sarbaz1mojood
							}
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezsarbaz2) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, vazirsatr, vazirsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezasb) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, vazirsatr, vazirsotoon, setplayer, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha

					}
				}
				if (vazir)
				{
					yekharekat = true;
					//cout << "okvazir";
					easyallow = false;
					break;
				}
				if (!vazir) {

					//	cout << " vaziram nist\n";
					continue;

				}
			}
			if (cost[j] == 4)
			{

				//		cout << "cost:" << cost[j] << "costn:" << costn[j] << endl;
				if (setplayer == '1')
				{
					if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
						satrsarbazjadid = 0;
						sotoonsarbazjadid = 0;
						bool sarbaz1_trial = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

								sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);

						}
						else
						{
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezsarbaz == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezasb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezvazir&&yekharekatmojazzarb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz2(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha
					}
					if (sarbaz1) {
						yekharekat = true;
						//		cout << "sarbaz1barghararast";
						easyallow = false;
						break;
					}
					if (!sarbaz1&&sarbaz2mojood == true) {

						if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
							satrsarbazjadid = 0;
							sotoonsarbazjadid = 0;
							bool sarbaz2_trial = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
							if (sarbaz1harif)
								canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (sarbaz2harif)
								canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (asbharif)
								canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
							if (vazirharif)
								canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
								if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

									sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
							}//if trueha
							else
							{
								if (sarbaz1mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezsarbaz == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}//if sarbaz2mojood
									}
								}
								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezasb == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}//if asbmojood
									}
								}
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezvazir == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz2(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}
							}//else trueha
						}
					}
					if (sarbaz2) {
						yekharekat = true;
						//	cout << "sarbaz2 barghararast";
						//	cout << sarbaz2satr;
						easyallow = false;
						break;
					}
				}

				else
				{
					if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0 && sarbaz1mojood == true) {
						satrsarbazjadid = -1;
						sotoonsarbazjadid = -1;
						bool sarbaz1_trial = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1nam);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
						}//if trueha
						else
						{
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezsarbaz == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezasb == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
								if (mohafezvazir == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											sarbaz1 = zarbsarbaz(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha
					}
					if (sarbaz1) {
						//		cout << "sarbaz1barghararast";
						easyallow = false;
						yekharekat = true;
						break;
					}
					if (!sarbaz1&&sarbaz2mojood == true) {
						if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
							satrsarbazjadid = -1;
							sotoonsarbazjadid = -1;
							bool sarbaz2_trial = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, &satrsarbazjadid, &sotoonsarbazjadid, true);
							if (sarbaz1harif)
								canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (sarbaz2harif)
								canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (asbharif)
								canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrsarbazjadid, sotoonsarbazjadid);
							if (vazirharif)
								canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz2nam);
							if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
								if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

									sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);

							}
							else
							{
								if (sarbaz1mojood)
								{

									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezsarbaz == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}//if sarbaz2mojood

								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezasb == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}//if asbmojood
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map);
									if (mohafezvazir == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, satrsarbazjadid, sotoonsarbazjadid, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											if (!vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

												sarbaz2 = zarbsarbaz(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, costn[j], map, khodi, 0, 0, false);
										}
									}
								}
							}//else trueha
						}
					}
					if (sarbaz2) {
						//	cout << "sarbaz2 barghararast";
						//	cout << sarbaz2satr;
						easyallow = false;
						yekharekat = true;
						break;
					}
				}


				if (!sarbaz2&&asbmojood == true) {
					if (asbsatr >= 0 && asbsotoon >= 0) {
						satrasbjadid = -1;
						sotoonasbjadid = -1;

						bool asb_trial = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, &satrasbjadid, &sotoonasbjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrasbjadid, sotoonasbjadid);
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrasbjadid, sotoonasbjadid, map, asbnam);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

								asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);

						}//if trueha
						else
						{
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrasbjadid, sotoonasbjadid, map);
								if (mohafezsarbaz1) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, asbsatr, asbsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}//if sarbaz1mojood
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrasbjadid, sotoonasbjadid, map);
								if (mohafezsarbaz2 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, asbsatr, asbsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))

											asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, satrasbjadid, sotoonasbjadid, map);
								if (mohafezvazir == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, asbsatr, asbsotoon, setplayer, vazirsatr, vazirsotoon, satrasbjadid, sotoonasbjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										if (!vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map))
											asb = zarbasb(asbsatr, asbsotoon, asbnam, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha
					}
				}

				if (asb) {
					//	cout << "asb";
					easyallow = false;
					yekharekat = true;
					break;
				}

				if (!asb) {

					//	cin >> satr;
					int satrvazirjadid = -1, sotoonvazirjadid = -1;
					//cout << "asb nist";
					//cout << "s" << asbsatr << asbsotoon;
					//	int a;
					//cin >> a;

					if (vazirsatr >= 0 && vazirsotoon >= 0 && vazirmojood == true) {
						bool vazir_trial = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, &satrvazirjadid, &sotoonvazirjadid, true);
						if (sarbaz1harif)
							canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (sarbaz2harif)
							canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (asbharif)
							canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satrvazirjadid, sotoonvazirjadid);
						//cout << satrvazirjadid << sotoonvazirjadid;
						if (vazirharif)
							canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satrvazirjadid, sotoonvazirjadid, map, vazirnammm);
						if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
							vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
						}//if trueha
						else
						{
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz1 = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezsarbaz1 == true) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, vazirsatr, vazirsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}//if sarbaz1mojood
							}
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezsarbaz2) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, vazirsatr, vazirsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map);
								if (mohafezasb) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, vazirsatr, vazirsotoon, setplayer, asbsatr, asbsotoon, satrvazirjadid, sotoonvazirjadid, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false) {
										vazir = zarbvazir(vazirsatr, vazirsotoon, vazirnammm, costn[j], map, khodi, 0, 0, false);
									}
								}
							}
						}//else trueha

					}
				}
				if (vazir)
				{
					//cout << "okvazir";
					easyallow = false;
					yekharekat = true;
					break;
				}
				if (!vazir) {

					//	cout << " vaziram nist\n";
					continue;

				}
			}
		}

		////////////////////////////چک اینکه میتونیم مهره حریفو تهدید کنیم یا نه
		if (easyallow == true && yekharekat == false)
		{

			//////////////////vazir/////////////////////
			//اگه مهره های وزیر واسب محافظ سرباز داشتن  حرکت تهدیدی نکنن
			if (yekharekat == false && easyallow == true) {

				//گفتیم اول وزیرو تهدیدکن بعد اسب بعد سربازا
				//mohafezghabelzadanmikhad
				//براي وزير اسب درخطر است نذاشتيمممممم
				//cout << "vazirrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr";
				//cout << "!asb";

				if (vazirsatr >= 0 && vazirsotoon >= 0) {//baraye halataye <5 ham badan bezar

					if (vazirmojood == true) {


						int meghdarharekati = 0;
						//							int khatarvazir;
						int vazirnewsatr = 0, vazirnewsotoon = 0;
						//1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
						//ابتدا مهره درخطر را پيدا ميکنيم
						//bool farar_az_sarbaz1harif;
						bool vazir_easyy;
						int jahatvazir = 1;
						int jahatforeasy = 0;
						bool sarbaz1darkhatar = false, sarbaz2darkhatar = false, asbdarkhatar = false, vazirdarkhatar = false;
						bool vz_mohafeze_s1e = false, vz_mohafeze_s2e = false, vz_mohafeze_asbe = false;
						if (yekharekat == false && easyallow == true) {
							/////////////////////////چک میکنیم ک ایا وزیر محافظ مهره ای هست یا نه /////////////////////////////
							if (sarbaz1mojood)
								vz_mohafeze_s1e = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr, sarbaz1sotoon, map);
							if (sarbaz2mojood)
								vz_mohafeze_s2e = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr, sarbaz2sotoon, map);
							if (asbmojood)
								vz_mohafeze_asbe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);

							/////////////////////////////////////////////////////////
							if (vz_mohafeze_s1e == false && vz_mohafeze_s2e == false && vz_mohafeze_asbe == false) {
								for (int jahatvazir2 = 0; jahatvazir2 < 8; jahatvazir2++) {

									//	bool vazir_easy(char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, bool khataryab)
									vazir_easyy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);
									//bool vazir_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* khatar, int* meghdarharekati = 0, bool khataryab = false)
									//بيايم بگيم  يه جهت  ساده تو قسمت ايزي الو تعريف کنيم
									//بعد بعد چک کردن 4 کن گو و ايف اصلي بگيم اگه ايف نقض شد 
									//تو السش اول جهت يکي اضافه بشه بعد دوباره وزير فور ايزي اجرا ببشه
									//تا زماني ک ايف اصليمون (4تا شرطه)ترو بشه
									//براي بقيه مهرهام همينکارو بکن
									int jahathayemojaz[6] = { 0 };

									//	cout << "\nvazirNew" << jahatvazir;
									if (sarbaz1harif)
										cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
									if (sarbaz2harif)
										cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
									if (asbharif)
										cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
									if (vazirharif)
										cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
									//	cout << cangofromasb;//5 mide
									//cin >> khatar;
									if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
									{
										bool vazirmohafezdarad = false;
										/*if (sarbaz1mojood)
										{//mohafez sarbz bedard vazir nmikhore
										bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, vazirnewsatr, vazirnewsotoon, map);
										if (mohafezsarbaz)
										vazirmohafezdarad = true;
										}//if sarbaz1mojood
										*/
										/*if (sarbaz2mojood)
										{
										bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, vazirnewsatr, vazirnewsotoon, map);
										if (mohafezsarbaz2)
										vazirmohafezdarad = true;
										}//if sarbaz2mojood
										*/
										if (asbmojood)
										{
											bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, vazirnewsatr, vazirnewsotoon, map);
											if (mohafezasb)
												vazirmohafezdarad = true;
										}//if asbmojood
										if (vazirmohafezdarad)
										{

											bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, vazirsatr, vazirsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
											if (asbdarkhatarast == false) {
												bool cantahdid = can_zarb_for_tahdid(setplayer, 4, 0, 0, sarbaz1nam, 0, 0
													, sarbaz2nam, 0, 0, vazirnewsatr, vazirnewsotoon, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
													, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
												if (cantahdid == true) {
													vazirforeasy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, false);

													if (vazirforeasy) {
														yekharekat = true;
														easyallow = false;
														break;
													}
												}
											}
										}
									}


									if (vazir_easyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
										//cout << vazirnewsatr << vazirnewsotoon;
										//cin >> yekharekat;
										//bool vazir_easy(char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, bool khataryab)
										bool cantahdid = can_zarb_for_tahdid(setplayer, 4, 0, 0, sarbaz1nam, 0, 0
											, sarbaz2nam, 0, 0, vazirnewsatr, vazirnewsotoon, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
											, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
										if (cantahdid == true) {
											vazirforeasy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, false);
											if (vazirforeasy) {
												yekharekat = true;
												easyallow = false;
												break;
											}
										}
									}
									else {
										//if (jahatvazir == 8)
										//vazirforeasy = false;

										jahatvazir++;
										//							vazirforeasy = false;
									}
								}//forjahatvazir
							}
							//}

							if (yekharekat == false && vazirforeasy)
							{
								easyallow = false;
								yekharekat = true;
								//cout << "vazireasybargharar";
							}
						}
					}
				}
			}
			//////////////////etmam vazir////////////////


		}//eaye=true


		 ///////////////////////////////////////////////////////////////
		 /*	if (easyallow == true && yekharekat == false) {
		 ///////////////////////////
		 bool sarbaz1mohafezeshe=false, sarbaz2mohafezeshe=false, vazirmohafezeshe=false, asbmohafezeshe = false;
		 bool asbdarkhatar = false, sarbaz1darkhatar = false, sarbaz2darkhatar = false, vazirdarkhatar = false;//doroste ghesmati braye farar mohreha dashtim ama darsoorti ke harekat sade amn nadashte bashn mian inja ta vazir mohafezeshun she
		 int jahatmohreasb, jahatmohresarbaz1, jahatmohresarbaz2;
		 int jahathayemojaz[6] = { 0 };
		 int shomarande = 0;
		 int meghdarharekatsarbaz1[6] = { 0 }, meghdarharekatsarbaz2[6] = { 0 }, meghdarharekatasb[6] = { 0 }, meghdarharekatvazir[6] = { 0 };
		 search_mohre_darkhatar(setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, vazirmojood, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2sotoon, sarbaz1nam, sarbaz2satr, sarbaz2nam, vazirsatr, vazirsotoon, asbnam, vazirnammm, &sarbaz1darkhatar, &sarbaz2darkhatar, &asbdarkhatar, &vazirdarkhatar);
		 if (vazirmojood) {

		 if (asbdarkhatar&&sarbaz1darkhatar&&yekharekat == false)

		 {//motegheyeraye esharegaro jadid kon baraharkodoom

		 int meghdarforkhatar;
		 int jahathayeasb[6] = { 0 }, jahathayesarbaz1[6] = { 0 };
		 mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
		 mohre_kojaye_vazire(&jahatmohresarbaz1, sarbaz1satr, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
		 vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayeasb, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon);
		 vazir_easy_easy(&jahatmohresarbaz1, vazirsatr, vazirsotoon, jahathayesarbaz1, meghdarharekatsarbaz1, khodicount, khodi, sarbaz1satr, sarbaz1sotoon);
		 int vazirnewsatr = 0, vazirnewsotoon = 0;
		 for (shomarande = 0; shomarande < sizeof jahathayeasb / sizeof(int); shomarande++) {
		 if (yekharekat == true)
		 break;

		 for (int shomarandes1 = 0; shomarandes1 < sizeof jahathayesarbaz1 / sizeof(int); shomarandes1++)
		 {

		 if (jahathayeasb[shomarande] == jahathayesarbaz1[shomarandes1])
		 {
		 int jahatmoshtarak = jahathayeasb[shomarande];
		 int meghdarharekatmoshtarak = meghdarharekatasb[shomarande];

		 bool vazir_easy_go1 = vazir_easy(&meghdarforkhatar, setplayer, &jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);

		 if (vazir_easy_go1 == true)
		 {
		 map[vazirnewsatr][vazirnewsotoon] = vazirnammm;
		 map[vazirsatr][vazirsotoon] = '-';
		 bool vazir_mitune_mohafez_asb = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, asbsatr, asbsotoon, map);
		 bool vazir_mitune_mohafez_sarbaz = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, sarbaz2satr, sarbaz2sotoon, map);
		 if (vazir_mitune_mohafez_asb == true && vazir_mitune_mohafez_sarbaz == true) {
		 if (vazirharif)
		 canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, 'v');
		 if (asbharif)
		 canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
		 if (canescapefromasb == true && canescapefromvazir == true) {

		 bool vazir_easy_go2 = vazir_easy_for_khatar(khodi, jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, meghdarforkhatar, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
		 if (vazir_easy_go2 == true) {
		 yekharekat = true;
		 easyallow = false;

		 }
		 else {
		 map[vazirnewsatr][vazirnewsotoon] = '-';
		 map[vazirsatr][vazirsotoon] = vazirnammm;
		 }
		 //	if(mohafez_darad(setplayer,'v',vazirsatr,vazirsotoon
		 }
		 else {
		 map[vazirnewsatr][vazirnewsotoon] = '-';
		 map[vazirsatr][vazirsotoon] = vazirnammm;
		 }

		 }
		 else {
		 map[vazirnewsatr][vazirnewsotoon] = '-';
		 map[vazirsatr][vazirsotoon] = vazirnammm;
		 }
		 }
		 else
		 continue;
		 }
		 }
		 }

		 }
		 if (asbdarkhatar&&sarbaz2darkhatar&&yekharekat == false)

		 {//motegheyeraye esharegaro jadid kon baraharkodoom

		 int meghdarforkhatar;
		 int jahathayeasb[6] = { 0 }, jahathayesarbaz2[6] = { 0 };
		 mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
		 mohre_kojaye_vazire(&jahatmohresarbaz2, sarbaz2satr, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
		 vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayeasb, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon);
		 vazir_easy_easy(&jahatmohresarbaz2, vazirsatr, vazirsotoon, jahathayesarbaz2, meghdarharekatsarbaz2, khodicount, khodi, sarbaz2satr, sarbaz2sotoon);
		 int vazirnewsatr = 0, vazirnewsotoon = 0;

		 for (shomarande = 0; shomarande < sizeof jahathayeasb[shomarande] / sizeof(int); shomarande++) {
		 if (yekharekat == true)
		 break;
		 if ((sarbaz1mohafezeshe == true && sarbaz2mohafezeshe == false && vazirmohafezeshe == false) || (sarbaz2mohafezeshe == true && sarbaz1mohafezeshe == false && vazirmohafezeshe == false) || (vazirmohafezeshe == true && sarbaz1mohafezeshe == false && sarbaz2mohafezeshe == false) || (sarbaz1mohafezeshe == false && sarbaz2mohafezeshe == false && vazirmohafezeshe == false)) {

		 for (int shomarandes1 = 0; shomarandes1 < sizeof jahathayesarbaz2 / sizeof(int); shomarandes1++)
		 {

		 if (jahathayeasb[shomarande] == jahathayesarbaz2[shomarandes1])
		 {
		 int jahatmoshtarak = jahathayeasb[shomarande];
		 int meghdarharekatmoshtarak = meghdarharekatasb[shomarande];
		 bool vazir_easy_go1 = vazir_easy(&meghdarforkhatar, setplayer, &jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);

		 if (vazir_easy_go1 == true)
		 {
		 map[vazirnewsatr][vazirnewsotoon] = vazirnammm;
		 map[vazirsatr][vazirsotoon] = '-';
		 bool vazir_mitune_mohafez_asb = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, asbsatr, asbsotoon, map);
		 bool vazir_mitune_mohafez_sarbaz = mohafez_darad(setplayer, 3, vazirnewsatr, vazirnewsotoon, sarbaz2satr, sarbaz2sotoon, map);
		 if (vazir_mitune_mohafez_asb == true && vazir_mitune_mohafez_sarbaz == true) {
		 if (vazirharif)
		 canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, 'v');
		 if (asbharif)
		 canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
		 if (canescapefromasb == true && canescapefromvazir == true) {

		 bool vazir_easy_go2 = vazir_easy_for_khatar(khodi, jahatmoshtarak, vazirsatr, vazirsotoon, vazirnammm, meghdarforkhatar, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
		 if (vazir_easy_go2) {
		 yekharekat = true;
		 easyallow = false;
		 break;
		 }
		 else {
		 map[vazirnewsatr][vazirnewsotoon] = '-';
		 map[vazirsatr][vazirsotoon] = vazirnammm;
		 }
		 //	if(mohafez_darad(setplayer,'v',vazirsatr,vazirsotoon
		 }
		 else {
		 map[vazirnewsatr][vazirnewsotoon] = '-';
		 map[vazirsatr][vazirsotoon] = vazirnammm;
		 }

		 }
		 else {
		 map[vazirnewsatr][vazirnewsotoon] = '-';
		 map[vazirsatr][vazirsotoon] = vazirnammm;
		 }
		 }
		 else
		 continue;

		 }
		 }
		 }
		 }

		 }
		 if (asbdarkhatar == true && yekharekat == false)
		 {

		 if (sarbaz1mojood)
		 sarbaz1mohafezeshe = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbsatr, asbsotoon, map);
		 if (sarbaz2mojood)
		 sarbaz2mohafezeshe = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, map);

		 if (vazirmojood)
		 vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
		 if ( (sarbaz1mohafezeshe == true && sarbaz2mohafezeshe == false && vazirmohafezeshe == false) || (sarbaz2mohafezeshe==true&&sarbaz1mohafezeshe==false&&vazirmohafezeshe==false) ||(vazirmohafezeshe==true&&sarbaz1mohafezeshe==false&&sarbaz2mohafezeshe==false)||(sarbaz1mohafezeshe==false&&sarbaz2mohafezeshe==false&&vazirmohafezeshe==false) ) {

		 shomarande = 0;
		 mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
		 vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon);
		 bool vazir_easy_go = false;
		 //int countchandtameghdarsefre = 0, meghdarharekatasbok = 0;
		 /////shomaresh tedad anasor jahathaye mojaz
		 for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
		 cout << "\nshomarande:" << shomarande << endl;
		 if (meghdarharekatasb[shomarande] == 0)
		 continue;
		 //	bool vazir_easy_for_khatar(int jahat, int vazirsatr, int vazirsotoon, char sarnam, int meghdarharekat, char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon)
		 /*if (meghdarharekatasb[shomarande] == 0) {
		 countchandtameghdarsefre += 1;
		 if (countchandtameghdarsefre > 4)
		 meghdarharekatasbok = 1;
		 else
		 continue;
		 }
		 */
		 /////////////////////////part3
		 /*
		 vazir_easy_go = vazir_easy_for_khatar(khodi, jahatmohreasb, vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasb[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);
		 if (vazir_easy_go == true)
		 {
		 yekharekat = true;
		 easyallow = false;
		 break;
		 }
		 }
		 /*if (countchandtameghdarsefre > 4) {

		 for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
		 {
		 vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasbok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

		 if (vazir_easy_go)
		 {
		 yekharekat = true;
		 break;
		 }
		 else
		 continue;
		 }
		 //}*/
		 ////////////part2
		 /*}
		 }
		 if (sarbaz1darkhatar == true && yekharekat == false)
		 {
		 if (sarbaz2mojood)
		 sarbaz2mohafezeshe = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
		 if (asbmojood)
		 asbmohafezeshe = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr, sarbaz1sotoon, map);
		 if (vazirmojood)
		 vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr, sarbaz1sotoon, map);
		 //if (sarbaz2mohafezeshe == false && asbmohafezeshe == false && vazirmohafezeshe == false) {
		 if ((sarbaz1mohafezeshe == true && vazirmohafezeshe == false && asbmohafezeshe == false) || (vazirmohafezeshe == true && sarbaz1mohafezeshe == false && asbmohafezeshe == false) || (asbmohafezeshe == true && vazirmohafezeshe == false && sarbaz1mohafezeshe == false)||(vazirmohafezeshe==false&&asbmohafezeshe==false&&sarbaz2mohafezeshe==false)) {

		 shomarande = 0;
		 cout << sarbaz1satr << sarbaz1sotoon;

		 mohre_kojaye_vazire(&jahatmohresarbaz1, sarbaz1satr, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
		 vazir_easy_easy(&jahatmohresarbaz1, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatsarbaz1, khodicount, khodi, sarbaz1satr, sarbaz1sotoon);
		 bool aya_vazir_mohafez_asb = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
		 //if (aya_vazir_mohafez_asb == false) {
		 bool vazir_easy_go = false;
		 /////shomaresh tedad anasor jahathaye mojaz
		 int countchandtameghdarsefre = 0;
		 int meghdarharekatsarbaz1ok = 0;
		 for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
		 if (meghdarharekatsarbaz1[shomarande] == 0) {
		 countchandtameghdarsefre += 1;
		 if (countchandtameghdarsefre > 4)
		 meghdarharekatsarbaz1ok = 1;
		 else
		 continue;
		 }

		 vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz1[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

		 if (vazir_easy_go)
		 {
		 yekharekat = true;
		 easyallow = false;
		 break;

		 }
		 else
		 continue;
		 }

		 if (countchandtameghdarsefre > 4) {

		 for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
		 {
		 vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz1ok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

		 if (vazir_easy_go)
		 {
		 yekharekat = true;
		 easyallow = false;
		 break;
		 }
		 else
		 continue;
		 }


		 }

		 //}
		 }
		 }
		 if (sarbaz2darkhatar == true && yekharekat == false)
		 {

		 if (sarbaz1mojood)
		 sarbaz1mohafezeshe = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
		 if (asbmojood)
		 asbmohafezeshe = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr, sarbaz2sotoon, map);
		 if (vazirmojood)
		 vazirmohafezeshe = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr, sarbaz2sotoon, map);
		 //if (sarbaz1mohafezeshe == false && asbmohafezeshe == false && vazirmohafezeshe == false) {
		 if( (sarbaz1mohafezeshe==true&&vazirmohafezeshe==false&&asbmohafezeshe==false) || (vazirmohafezeshe==true&&sarbaz1mohafezeshe==false&&asbmohafezeshe==false )|| (asbmohafezeshe==true&&vazirmohafezeshe==false&&sarbaz1mohafezeshe==false||(vazirmohafezeshe == false && asbmohafezeshe == false && sarbaz2mohafezeshe == false)) ){
		 int countchandtameghdarsefre = 0, meghdarharekatsarbaz2ok = 1;
		 shomarande = 0;
		 mohre_kojaye_vazire(&jahatmohresarbaz2, sarbaz2satr, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
		 vazir_easy_easy(&jahatmohresarbaz2, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatsarbaz2, khodicount, khodi, sarbaz2satr, sarbaz2sotoon);

		 bool aya_vazir_mohafez_asb = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map);
		 if (aya_vazir_mohafez_asb == false) {
		 bool vazir_easy_go = false;

		 /////shomaresh tedad anasor jahathaye mojaz
		 for (shomarande = 0; shomarande < sizeof jahathayemojaz / sizeof(int); shomarande++) {
		 if (meghdarharekatsarbaz2[shomarande] == 0) {
		 countchandtameghdarsefre += 1;
		 if (countchandtameghdarsefre > 4)
		 meghdarharekatsarbaz2ok = 1;
		 else
		 continue;
		 }
		 vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz2[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

		 if (vazir_easy_go)
		 {

		 yekharekat = true;
		 easyallow = false;
		 break;
		 }
		 }

		 if (countchandtameghdarsefre > 4) {

		 for (shomarande = 0; jahathayemojaz[shomarande] > 0; shomarande++)
		 {
		 vazir_easy_go = vazir_easy_for_khatar(khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz2ok, setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

		 if (vazir_easy_go)
		 {
		 yekharekat = true;
		 easyallow = false;
		 break;
		 }
		 else
		 continue;
		 }
		 }
		 }
		 }
		 }
		 }


		 }	//ifvazirmojood
		 */
		 ///////////////////////////////////
		 ///////////////////////////////تهدید بعد از اسب به اینجا منتقل شدن/////////////////
		 ///////////////////asb///////////////////
		if (yekharekat == false && easyallow == true) {

			if (asbsatr >= 0 && asbsotoon >= 0) {
				int countasbzarbpazir = 0, tedadmohafezasb = 0;
				int jahatasb = 1;
				int asbnewsatr = 0, asbnewsotoon = 0;
				if (asbmojood == true) {
					//mohafezghabelzadanedarad
					for (int jahatasb2 = 0; jahatasb2 < 8; jahatasb2++) {
						bool asbeasyy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, true);
						//	cin >> asbmojood;
						//avval yebar tabero ejra kon ta bedun ke mohre ba harekat sade mikhad koja bere
						//(maghadirmahal jadid ke bayad be sat o sot asb ezafe shan)
						//1:2balachap 2:2balarast 3-2paeinchap 4-2paeinrast 5-1balachap 6-1balarast 7-1paeinchap 8-1paeinrast
						//	cout << jahatasb;

						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
						if (cangofromsarbaz1 == false)
							countasbzarbpazir += 1;
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
						if (cangofromsarbaz2 == false)
							countasbzarbpazir += 1;
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, asbnewsatr, asbnewsotoon);
						if (cangofromasb == false)
							countasbzarbpazir += 1;
						if (vazirharif)
							if (cangofromvazir == false)
								countasbzarbpazir += 1;
						cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
						if (jahatasb > 8)
							asbforeasy = false;

						if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
						{
							bool asbmohafezdarad = false;
							/*	if (sarbaz1mojood)
							{محافظ سرباز بدرد حرکت تهدیدی اسب نمیخوره
							bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbnewsatr, asbnewsotoon, map);
							if (mohafezsarbaz) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, asbsatr, asbsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
							sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
							, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
							asbmohafezdarad = true;
							tedadmohafezasb += 1;
							}
							}
							}//if sarbaz1mojood
							if (sarbaz2mojood)
							{
							bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbnewsatr, asbnewsotoon, map);
							if (mohafezsarbaz2) {
							bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, asbsatr, asbsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
							sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
							, vazirharifsatr, vazirharifsotoon);
							if (mohafezghabelzadane == false) {
							asbmohafezdarad = true;
							tedadmohafezasb += 1;
							}
							}//if sarbaz2mojood
							}
							*/
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbnewsatr, asbnewsotoon, map);
								if (mohafezvazir) {
									if (cangofromsarbaz1 == true || cangofromsarbaz1 == true) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, asbsatr, asbsotoon, setplayer, vazirsatr, vazirsotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											asbmohafezdarad = true;
											tedadmohafezasb += 1;
										}
									}
								}
							}//if asbmojood
							if (asbmohafezdarad&&tedadmohafezasb >= countasbzarbpazir)
							{

								bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								//bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false) {
									bool cantahdid = can_zarb_for_tahdid(setplayer, 3, 0, 0, sarbaz1nam, 0, 0
										, sarbaz2nam, asbnewsatr, asbnewsotoon, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
										, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
									if (cantahdid == true) {
										asbforeasy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, false);

										if (asbforeasy == true) {
											yekharekat = true;
											easyallow = false;
											break;
										}
									}
								}
							}
						}


						if (asbeasyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {

							//cout << "ejra shod";
							//cin >> khatar;
							bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);

							if (vazirdarkhatarast == false) {
								bool cantahdid = can_zarb_for_tahdid(setplayer, 3, 0, 0, sarbaz1nam, 0, 0
									, sarbaz2nam, asbnewsatr, asbnewsotoon, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
									, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
								if (cantahdid == true) {
									asbforeasy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, false);
									if (asbforeasy == true) {
										yekharekat = true;
										easyallow = false;
										break;
									}
								}
							}
						}
						else {
							if (jahatasb > 8)
								break;
							jahatasb++;
						}

					}//forjahatasb2

				}
			}
		}


		////////////////////etmam asb///////////////////
		//mohafezbandi in ghesmatmoonde
		if (easyallow = true && yekharekat == false) {
			if (setplayer == '1')
			{


				if (sarbaz1satr <= 5 && sarbaz1sotoon <= 5) {
					if (s1counter > 25)
						sarbaz1foreasy = false;
					if (sarbaz1mojood == true) {
						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz2nam);
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr + 1, sarbaz1sotoon);
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
						if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
						{
							bool sarbaz1mohafezdarad = false;
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
								if (mohafezsarbaz)
									sarbaz1mohafezdarad = true;
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
								if (mohafezasb)
									sarbaz1mohafezdarad = true;
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
								if (mohafezvazir)
									sarbaz1mohafezdarad = true;
							}
							if (sarbaz1mohafezdarad)
							{
								bool 	vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								bool 	asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false && asbdarkhatarast == false) {

									//bool aya_mitavanad_sade_harekat(char setplayer, int noemohre, int satrmohre, int sotoonmohre, int sarbaz1satr, int sarbaz1sotoon, int asbsatr, int asbsotoon, int vazirsatr, int vazirsotoon, bool aya_mohre_mohafez_s1, bool aya_mohre_mohafez_s2, bool aya_mohre_mohafez_asb, bool aya_mohre_mohafez_vazir, char map[6][6])
									bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
									bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
									aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
									if (aya_mohre_mohafez_s2)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
									if (aya_mohre_mohafez_asb)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
									if (aya_mohre_mohafez_vazir)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
									if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {
										//حالا باید ببینیم آیا میشه تو محل جدید مهرهای حریفو بزنیم یا نه

										bool cantahdid = can_zarb_for_tahdid(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, sarbaz1nam, 0, 0
											, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
											, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
										if (cantahdid == true) {
											sarbaz1foreasy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
											if (sarbaz1foreasy) {
												yekharekat = true;
												easyallow = false;
											}
										}
									}
								}
							}
						}
						if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
							bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
							bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
							if (vazirdarkhatarast == false && asbdarkhatarast == false)
							{
								bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
								bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
								aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
								if (aya_mohre_mohafez_s2)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
								if (aya_mohre_mohafez_asb)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
								if (aya_mohre_mohafez_vazir)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
								if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {
									bool cantahdid = can_zarb_for_tahdid(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, sarbaz1nam, 0, 0
										, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
										, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
									if (cantahdid == true) {
										sarbaz1foreasy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
										if (sarbaz1foreasy) {
											yekharekat = true;
											easyallow = false;
										}
									}
								}

							}
						}
					}
				}
			}
			else {

				if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0) {
					if (s1counter > 25)
						sarbaz1foreasy = false;
					if (sarbaz1mojood == true) {

						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, (sarbaz1satr - 1), sarbaz1sotoon, map, sarbaz1nam);
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, (sarbaz1satr - 1), sarbaz1sotoon, map, sarbaz1nam);
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr - 1, sarbaz1sotoon);
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1nam);
						if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
						{//mohafezash dorost shod
							bool sarbaz1mohafezdarad = false;
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
								if (mohafezsarbaz) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz1mohafezdarad = true;

								}//if sarbaz2mojood
							}
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
								if (mohafezasb)
								{
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz1mohafezdarad = true;

								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
								if (mohafezvazir)
								{
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz1mohafezdarad = true;
								}
								if (sarbaz1mohafezdarad)
								{

									bool 	vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
										bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
										aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
										if (aya_mohre_mohafez_s2)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
										if (aya_mohre_mohafez_asb)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
										if (aya_mohre_mohafez_vazir)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
										if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {
											bool cantahdid = can_zarb_for_tahdid(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, sarbaz1nam, 0, 0
												, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
												, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
											if (cantahdid == true) {
												sarbaz1foreasy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
												if (sarbaz1foreasy) {
													yekharekat = true;

													easyallow = false;
												}
											}
										}
									}
								}
							}
							if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
								bool	vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								bool	asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false && asbdarkhatarast == false) {
									bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
									bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
									aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
									if (aya_mohre_mohafez_s2)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
									if (aya_mohre_mohafez_asb)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
									if (aya_mohre_mohafez_vazir)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
									if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {
										bool cantahdid = can_zarb_for_tahdid(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, sarbaz1nam, 0, 0
											, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
											, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
										if (cantahdid == true) {
											sarbaz1foreasy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
											if (sarbaz1foreasy) {
												easyallow = false;
												yekharekat = true;
											}
										}
									}
								}
							}
						}
					}
				}
				if (sarbaz1foreasy) {
					s1counter++;
					//cout << "sarbaz1easy go";
					//cout << sarbaz1satr;
					easyallow = false;
					yekharekat = true;
				}
				/////////////////////////sarbaz2///////////////////
			}
		}
		if (yekharekat == false && !sarbaz1foreasy) {

			if (setplayer == '1')
			{

				//mohafezghabelzadandare
				if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
					if (s2counter > 25)
						sarbaz2foreasy = false;
					if (sarbaz2mojood == true) {

						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr + 1, sarbaz2sotoon);
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
						if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
						{
							bool sarbaz2mohafezdarad = false;
							if (sarbaz1mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr + 1, sarbaz2sotoon, map);

								if (mohafezsarbaz)
								{
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz2mohafezdarad = true;

								}
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
								if (mohafezasb)
								{
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz2mohafezdarad = true;
								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
								if (mohafezvazir) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz2mohafezdarad = true;
								}
							}
							if (sarbaz2mohafezdarad)
							{
								bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false && asbdarkhatarast == false) {
									bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
									bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
									aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
									if (aya_mohre_mohafez_s1)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
									if (aya_mohre_mohafez_asb)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
									if (aya_mohre_mohafez_vazir)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
									if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
										bool cantahdid = can_zarb_for_tahdid(setplayer, 2, 0, 0, sarbaz1nam, sarbaz2satr + 1, sarbaz2sotoon
											, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
											, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
										if (cantahdid == true) {
											sarbaz2foreasy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
											if (sarbaz2foreasy) {
												easyallow = false;
												yekharekat = true;
											}
										}
									}
								}
							}
						}

						if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
							bool vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
							bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
							if (vazirdarkhatarast == false && asbdarkhatarast == false)
							{
								bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
								bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
								aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
								if (aya_mohre_mohafez_s1)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
								if (aya_mohre_mohafez_asb)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
								if (aya_mohre_mohafez_vazir)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
								if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
									bool cantahdid = can_zarb_for_tahdid(setplayer, 2, 0, 0, sarbaz1nam, sarbaz2satr + 1, sarbaz2sotoon
										, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
										, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
									if (cantahdid == true) {

										sarbaz2foreasy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
										if (sarbaz2foreasy == true) {
											yekharekat = true;
											easyallow = false;
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				if (sarbaz2satr >= 0 && sarbaz2sotoon >= 0) {
					if (s2counter > 25)
						sarbaz2foreasy = false;
					if (sarbaz2mojood == true) {
						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr - 1, sarbaz2sotoon);
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
						if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
							bool	vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
							bool asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
							if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
							{
								bool sarbaz2mohafezdarad = false;
								if (sarbaz1mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
									if (mohafezsarbaz) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false)
											sarbaz2mohafezdarad = true;

									}
								}//if sarbaz2mojood
								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
									if (mohafezasb) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false)
											sarbaz2mohafezdarad = true;

									}
								}//if asbmojood
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
									if (mohafezvazir) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false)
											sarbaz2mohafezdarad = true;

									}
								}
								if (sarbaz2mohafezdarad)
								{
									vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
										bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
										aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
										if (aya_mohre_mohafez_s1)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
										if (aya_mohre_mohafez_asb)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
										if (aya_mohre_mohafez_vazir)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
										if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
											bool cantahdid = can_zarb_for_tahdid(setplayer, 2, 0, 0, sarbaz1nam, sarbaz2satr - 1, sarbaz2sotoon
												, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
												, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
											if (cantahdid == true) {
												sarbaz2foreasy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
												if (sarbaz2foreasy == true) {
													yekharekat = true;
													easyallow = false;
												}
											}
										}
									}
								}
							}

							if (vazirdarkhatarast == false && asbdarkhatarast == false)
							{
								bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
								bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
								aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
								if (aya_mohre_mohafez_s1)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
								if (aya_mohre_mohafez_asb)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
								if (aya_mohre_mohafez_vazir)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
								if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
									bool cantahdid = can_zarb_for_tahdid(setplayer, 2, 0, 0, sarbaz1nam, sarbaz2satr - 1, sarbaz2sotoon
										, sarbaz2nam, 0, 0, 0, 0, vazirnammm, sarbaz1harif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harif
										, sarbaz2harifsatr, sarbaz2harifsotoon, asbharif, asbharifsatr, asbharifsotoon, vazirharif, vazirharifsatr, vazirharifsotoon);
									if (cantahdid == true) {
										sarbaz2foreasy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
										if (sarbaz2foreasy == true) {
											yekharekat = true;
											easyallow = false;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (sarbaz2foreasy) {
			s2counter++;
			//cout << "sarbaz2easy go";
			//cout << sarbaz2satr;.
			easyallow = false;
			yekharekat = true;
		}




		/////////////////////////////////////////////////////////////////////////


		bool vazirdarkhatarast = true, asbdarkhatarast = true;
		if (yekharekat == false && easyallow == true) {

			//mohafezbandi in ghesmatmoonde
			if (setplayer == '1')
			{


				if (sarbaz1satr <= 5 && sarbaz1sotoon <= 5) {
					if (s1counter > 25)
						sarbaz1foreasy = false;
					if (sarbaz1mojood == true) {
						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz2nam);
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr + 1, sarbaz1sotoon);
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr + 1, sarbaz1sotoon, map, sarbaz1nam);
						if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
						{
							bool sarbaz1mohafezdarad = false;
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
								if (mohafezsarbaz)
									sarbaz1mohafezdarad = true;
							}//if sarbaz2mojood
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
								if (mohafezasb)
									sarbaz1mohafezdarad = true;
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr + 1, sarbaz1sotoon, map);
								if (mohafezvazir)
									sarbaz1mohafezdarad = true;
							}
							if (sarbaz1mohafezdarad)
							{
								vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false && asbdarkhatarast == false) {

									//bool aya_mitavanad_sade_harekat(char setplayer, int noemohre, int satrmohre, int sotoonmohre, int sarbaz1satr, int sarbaz1sotoon, int asbsatr, int asbsotoon, int vazirsatr, int vazirsotoon, bool aya_mohre_mohafez_s1, bool aya_mohre_mohafez_s2, bool aya_mohre_mohafez_asb, bool aya_mohre_mohafez_vazir, char map[6][6])
									bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
									bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
									aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
									if (aya_mohre_mohafez_s2)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
									if (aya_mohre_mohafez_asb)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
									if (aya_mohre_mohafez_vazir)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
									if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {

										sarbaz1foreasy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
										if (sarbaz1foreasy == true) {
											yekharekat = true;
											easyallow = false;
										}
									}
								}
							}
						}
						if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
							vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
							asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
							if (vazirdarkhatarast == false && asbdarkhatarast == false)
							{
								bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
								bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
								aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
								if (aya_mohre_mohafez_s2)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
								if (aya_mohre_mohafez_asb)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
								if (aya_mohre_mohafez_vazir)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr + 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
								if (cankeeps2 == true && cankeepasb == true && cankeepvazir == true) {
									sarbaz1foreasy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
									if (sarbaz1foreasy == true) {
										yekharekat = true;
										easyallow = false;
									}
								}

							}
						}
					}
				}
			}
			else {

				if (sarbaz1satr >= 0 && sarbaz1sotoon >= 0) {
					if (s1counter > 25)
						sarbaz1foreasy = false;
					if (sarbaz1mojood == true) {

						if (sarbaz1harif)
							cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, (sarbaz1satr - 1), sarbaz1sotoon, map, sarbaz1nam);
						if (sarbaz2harif)
							cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, (sarbaz1satr - 1), sarbaz1sotoon, map, sarbaz1nam);
						if (asbharif)
							cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr - 1, sarbaz1sotoon);
						if (vazirharif)
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1nam);
						if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
						{//mohafezash dorost shod
							bool sarbaz1mohafezdarad = false;
							if (sarbaz2mojood)
							{
								bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
								if (mohafezsarbaz) {
									bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, sarbaz1satr, sarbaz1sotoon, setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz1mohafezdarad = true;

								}//if sarbaz2mojood
							}
							if (asbmojood)
							{
								bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
								if (mohafezasb)
								{
									bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz1satr, sarbaz1sotoon, setplayer, asbsatr, asbsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz1mohafezdarad = true;

								}
							}//if asbmojood
							if (vazirmojood)
							{
								bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz1satr - 1, sarbaz1sotoon, map);
								if (mohafezvazir)
								{
									bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz1satr, sarbaz1sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz1satr - 1, sarbaz1sotoon, map, sarbaz1harif,
										sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
										, vazirharifsatr, vazirharifsotoon);
									if (mohafezghabelzadane == false)
										sarbaz1mohafezdarad = true;
								}
								if (sarbaz1mohafezdarad)
								{

									vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
										bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
										aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
										if (aya_mohre_mohafez_s2)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
										if (aya_mohre_mohafez_asb)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
										if (aya_mohre_mohafez_vazir)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
										if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {
											sarbaz1foreasy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
											if (sarbaz1foreasy) {
												yekharekat = true;
												easyallow = false;
											}
										}
									}
								}
							}
						}
						if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
							vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
							asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
							if (vazirdarkhatarast == false && asbdarkhatarast == false) {
								bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
								bool cankeeps2 = true, cankeepasb = true, cankeepvazir = true;
								aya_mitavanad_sade_harekat(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
								if (aya_mohre_mohafez_s2)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeeps2 = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, map);
								if (aya_mohre_mohafez_asb)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepasb = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, asbsatr, asbsotoon, map);
								if (aya_mohre_mohafez_vazir)
									//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
									cankeepvazir = mohafez_darad(setplayer, 1, sarbaz1satr - 1, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
								if (cankeeps2 == true && cankeepasb&&cankeepvazir == true) {
									sarbaz1foreasy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
									if (sarbaz1foreasy) {
										yekharekat = true;
										easyallow = false;
									}
								}
							}

						}

					}
				}
				if (sarbaz1foreasy) {
					s1counter++;
					//cout << "sarbaz1easy go";
					//cout << sarbaz1satr;
					yekharekat = true;
					easyallow = false;
				}
			}
			if (yekharekat == false && !sarbaz1foreasy) {

				if (setplayer == '1')
				{
					//mohafezghabelzadandare
					if (sarbaz2satr <= 5 && sarbaz2sotoon <= 5) {
						if (s2counter > 25)
							sarbaz2foreasy = false;
						if (sarbaz2mojood == true) {

							if (sarbaz1harif)
								cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
							if (sarbaz2harif)
								cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
							if (asbharif)
								cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr + 1, sarbaz2sotoon);
							if (vazirharif)
								cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz2nam);
							if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
							{
								bool sarbaz2mohafezdarad = false;
								if (sarbaz1mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr + 1, sarbaz2sotoon, map);

									if (mohafezsarbaz)
									{
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false)
											sarbaz2mohafezdarad = true;

									}
								}//if sarbaz2mojood
								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
									if (mohafezasb)
									{
										bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false)
											sarbaz2mohafezdarad = true;
									}
								}//if asbmojood
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr + 1, sarbaz2sotoon, map);
									if (mohafezvazir) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz2satr + 1, sarbaz2sotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false)
											sarbaz2mohafezdarad = true;
									}
								}
								if (sarbaz2mohafezdarad)
								{
									vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
										bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
										aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
										if (aya_mohre_mohafez_s1)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
										if (aya_mohre_mohafez_asb)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
										if (aya_mohre_mohafez_vazir)
											//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
											cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
										if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
											sarbaz2foreasy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
											if (sarbaz2foreasy) {
												yekharekat = true;
												easyallow = false;
											}
										}
									}
								}
							}

							if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
								vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (vazirdarkhatarast == false && asbdarkhatarast == false)
								{
									bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
									bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
									aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
									if (aya_mohre_mohafez_s1)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
									if (aya_mohre_mohafez_asb)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
									if (aya_mohre_mohafez_vazir)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr + 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
									if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
										sarbaz2foreasy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
										if (sarbaz2foreasy) {
											yekharekat = true;
											easyallow = false;
										}
									}
								}
							}
						}
					}
				}
				else {

					if (sarbaz2satr >= 0 && sarbaz2sotoon >= 0) {
						if (s2counter > 25)
							sarbaz2foreasy = false;
						if (sarbaz2mojood == true) {
							if (sarbaz1harif)
								cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
							if (sarbaz2harif)
								cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
							if (asbharif)
								cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr - 1, sarbaz2sotoon);
							if (vazirharif)
								cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz2nam);
							if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
								vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
								asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
								if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
								{
									bool sarbaz2mohafezdarad = false;
									if (sarbaz1mojood)
									{
										bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
										if (mohafezsarbaz) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, sarbaz2satr, sarbaz2sotoon, setplayer, sarbaz1satr, sarbaz1sotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false)
												sarbaz2mohafezdarad = true;

										}
									}//if sarbaz2mojood
									if (asbmojood)
									{
										bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
										if (mohafezasb) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(asbnam, sarbaz2satr, sarbaz2sotoon, setplayer, asbsatr, asbsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false)
												sarbaz2mohafezdarad = true;

										}
									}//if asbmojood
									if (vazirmojood)
									{
										bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, sarbaz2satr - 1, sarbaz2sotoon, map);
										if (mohafezvazir) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, sarbaz2satr, sarbaz2sotoon, setplayer, vazirsatr, vazirsotoon, sarbaz2satr - 1, sarbaz2sotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false)
												sarbaz2mohafezdarad = true;

										}
									}
									if (sarbaz2mohafezdarad)
									{
										vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
										asbdarkhatarast = asb_dar_khatar_ast(setplayer, sarbaz2satr, sarbaz2sotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
										if (vazirdarkhatarast == false && asbdarkhatarast == false) {
											bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
											bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
											aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
											if (aya_mohre_mohafez_s1)
												//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
												cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
											if (aya_mohre_mohafez_asb)
												//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
												cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
											if (aya_mohre_mohafez_vazir)
												//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
												cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
											if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
												sarbaz2foreasy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
												if (sarbaz2foreasy) {
													yekharekat = true;
													easyallow = false;
												}
											}
										}
									}
								}

								if (vazirdarkhatarast == false && asbdarkhatarast == false)
								{
									bool aya_mohre_mohafez_s1 = false, aya_mohre_mohafez_s2 = false, aya_mohre_mohafez_asb = false, aya_mohre_mohafez_vazir = false;
									bool cankeeps1 = true, cankeepasb = true, cankeepvazir = true;
									aya_mitavanad_sade_harekat(setplayer, 1, sarbaz2satr, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, vazirsatr, vazirsotoon, &aya_mohre_mohafez_s1, &aya_mohre_mohafez_s2, &aya_mohre_mohafez_asb, &aya_mohre_mohafez_vazir, map);
									if (aya_mohre_mohafez_s1)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeeps1 = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, sarbaz1satr, sarbaz1sotoon, map);
									if (aya_mohre_mohafez_asb)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepasb = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, asbsatr, asbsotoon, map);
									if (aya_mohre_mohafez_vazir)
										//چک کنيم ببينيم تو محل جديدشم باز محافظش ميمونه يانه اگه نه حرکتش نده
										cankeepvazir = mohafez_darad(setplayer, 1, sarbaz2satr - 1, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
									if (cankeeps1 == true && cankeepasb&&cankeepvazir == true) {
										sarbaz2foreasy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
										if (sarbaz2foreasy) {
											yekharekat = true;
											easyallow = false;
										}
									}
								}
							}
						}
					}
				}
			}

			if (sarbaz2foreasy) {
				s2counter++;
				//cout << "sarbaz2easy go";
				//cout << sarbaz2satr;
				yekharekat = true;
				easyallow = false;
			}
			int khatar = 0;
			int jahatasb = 1;
			int asbnewsatr = 0, asbnewsotoon = 0;
			if (yekharekat == false && sarbaz2foreasy == false) {

				if (asbsatr >= 0 && asbsotoon >= 0) {
					int countasbzarbpazir = 0, tedadmohafezasb = 0;

					if (asbmojood == true) {
						//mohafezghabelzadanedarad
						for (int jahatasb2 = 0; jahatasb2 < 8; jahatasb2++) {
							bool asbeasyy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, true);
							//	cin >> asbmojood;
							//avval yebar tabero ejra kon ta bedun ke mohre ba harekat sade mikhad koja bere
							//(maghadirmahal jadid ke bayad be sat o sot asb ezafe shan)
							//1:2balachap 2:2balarast 3-2paeinchap 4-2paeinrast 5-1balachap 6-1balarast 7-1paeinchap 8-1paeinrast
							//	cout << jahatasb;

							if (sarbaz1harif)
								cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
							if (cangofromsarbaz1 == false)
								countasbzarbpazir += 1;
							if (sarbaz2harif)
								cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
							if (cangofromsarbaz2 == false)
								countasbzarbpazir += 1;
							if (asbharif)
								cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, asbnewsatr, asbnewsotoon);
							if (cangofromasb == false)
								countasbzarbpazir += 1;
							if (vazirharif)
								if (cangofromvazir == false)
									countasbzarbpazir += 1;
							cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbnewsatr, asbnewsotoon, map, asbnam);
							if (jahatasb > 8)
								asbforeasy = false;

							if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
							{
								bool asbmohafezdarad = false;
								if (sarbaz1mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, asbnewsatr, asbnewsotoon, map);
									if (mohafezsarbaz) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz1nam, asbsatr, asbsotoon, setplayer, sarbaz1satr, sarbaz1sotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											asbmohafezdarad = true;
											tedadmohafezasb += 1;
										}
									}
								}//if sarbaz1mojood
								if (sarbaz2mojood)
								{
									bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, asbnewsatr, asbnewsotoon, map);
									if (mohafezsarbaz2) {
										bool mohafezghabelzadane = mohafez_ghabelzadane(sarbaz2nam, asbsatr, asbsotoon, setplayer, sarbaz2satr, sarbaz2sotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
											sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
											, vazirharifsatr, vazirharifsotoon);
										if (mohafezghabelzadane == false) {
											asbmohafezdarad = true;
											tedadmohafezasb += 1;
										}
									}//if sarbaz2mojood
								}
								if (vazirmojood)
								{
									bool mohafezvazir = mohafez_darad(setplayer, 3, vazirsatr, vazirsotoon, asbnewsatr, asbnewsotoon, map);
									if (mohafezvazir) {
										if (cangofromsarbaz1 == true || cangofromsarbaz1 == true) {
											bool mohafezghabelzadane = mohafez_ghabelzadane(vazirnammm, asbsatr, asbsotoon, setplayer, vazirsatr, vazirsotoon, asbnewsatr, asbnewsotoon, map, sarbaz1harif,
												sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
												, vazirharifsatr, vazirharifsotoon);
											if (mohafezghabelzadane == false) {
												asbmohafezdarad = true;
												tedadmohafezasb += 1;
											}
										}
									}
								}//if asbmojood
								if (asbmohafezdarad == true && tedadmohafezasb >= countasbzarbpazir)
								{
									vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									if (vazirdarkhatarast == false) {
										asbforeasy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, false);
										if (asbforeasy == true) {
											yekharekat = true;
											easyallow = false;
											break;
										}
									}
								}
							}


							if (asbeasyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {

								//	cout << "ejra shod";
								//cin >> khatar;
								vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);

								if (vazirdarkhatarast == false) {
									asbforeasy = asb_easy(&jahatasb, asbsatr, asbsotoon, asbnam, map, khodi, &asbnewsatr, &asbnewsotoon, false);
									if (asbforeasy == true) {
										yekharekat = true;
										easyallow = false;
										break;
									}

								}
							}
							else {
								if (jahatasb > 8)
									break;
								jahatasb++;
							}

						}//forjahatasb2

					}
				}
			}

			/*	else
			asbforeasy = false;
			}
			//	else
			//	asbforeasy = false;

			}
			else
			asbforeasy = false;
			}

			/}
			*/
			/*	int asbnewsatr, int asbnewsotoon;
			int asbeasyy = asb_easy(asbsatr, asbsotoon, asbnam, map, khodi,true);
			asbeasyy[0] = asbnewsatr;
			asbeasyy[1] = asbnewsotoon;
			asbeasy =

			(asbsatr, asbsotoon, asbnam, map, khodi);
			}
			*/
		}

		if (yekharekat == false && easyallow == true && !asbforeasy) {
			//mohafezghabelzadanmikhad
			//براي وزير اسب درخطر است نذاشتيمممممم
			//cout << "vazirrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr";
			//cout << "!asb";

			if (vazirsatr >= 0 && vazirsotoon >= 0) {//baraye halataye <5 ham badan bezar

				if (vazirmojood == true && yekharekat == false) {


					int meghdarharekati = 0;
					//							int khatarvazir;
					int vazirnewsatr = 0, vazirnewsotoon = 0;
					//1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
					//ابتدا مهره درخطر را پيدا ميکنيم
					//	bool farar_az_sarbaz1harif;
					bool vazir_easyy;
					int jahatvazir = 1;
					int jahatforeasy = 0;
					bool sarbaz1darkhatar = false, sarbaz2darkhatar = false, asbdarkhatar = false, vazirdarkhatar = false;
					//(				char  setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int vazirmojood, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int asbsatr, int asbsotoon, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int sarbaz1satr,int sarbaz1sotoon, int sarbaz2sotoon, int sarbaz1nam, int sarbaz2satr, int sarbaz2nam, int vazirsatr, int vazirsotoon, int asbnam, int vazirnammm, bool* sarbaz1darkhatar, bool* sarbaz2darkhatar, bool* asbdarkhatar, bool* vazirdarkhatar)
					search_mohre_darkhatar(setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, vazirmojood, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, asbsatr, asbsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, sarbaz2sotoon, sarbaz1nam, sarbaz2satr, sarbaz2nam, vazirsatr, vazirsotoon, asbnam, vazirnammm, &sarbaz1darkhatar, &sarbaz2darkhatar, &asbdarkhatar, &vazirdarkhatar);
					int jahathayemojaz[6] = { 0 };			int jahatmohresarbaz1 = 0, jahatmohresarbaz2 = 0, jahatmohreasb = 0, jahatmohrevazir = 0;
					int meghdarharekatsarbaz1[6] = { 0 }, meghdarharekatsarbaz2[6] = { 0 }, meghdarharekatasb[6] = { 0 }, meghdarharekatvazir[6] = { 0 };
					int shomarande = 0;
					if (asbdarkhatar == true && yekharekat == false)
					{

						shomarande = 0;
						mohre_kojaye_vazire(&jahatmohreasb, asbsatr, asbsotoon, vazirsatr, vazirsotoon, map);
						vazir_easy_easy(&jahatmohreasb, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatasb, khodicount, khodi, asbsatr, asbsotoon, asbnam);
						bool vazir_easy_go = false;
						/////shomaresh tedad anasor jahathaye mojaz							
						//for (shomarande; jahathayemojaz[shomarande] > 0; shomarande++) {
						for (shomarande; shomarande<sizeof jahathayemojaz / sizeof(int); shomarande++) {
							//	bool vazir_easy_for_khatar(int jahat, int vazirsatr, int vazirsotoon, char sarnam, int meghdarharekat, char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon)
							if (meghdarharekatasb[shomarande] == 0)
								continue;
							vazir_easy_go = vazir_easy_for_khatar(asbsatr, asbsotoon, khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatasb[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

							if (vazir_easy_go == true)
							{
								yekharekat = true;
								easyallow = false;
								return;
							}
						}
					}
					if (sarbaz1darkhatar == true && yekharekat == false)
					{

						shomarande = 0;
						//cout << sarbaz1satr << sarbaz1sotoon;
						mohre_kojaye_vazire(&jahatmohresarbaz1, sarbaz1satr, sarbaz1sotoon, vazirsatr, vazirsotoon, map);
						vazir_easy_easy(&jahatmohresarbaz1, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatsarbaz1, khodicount, khodi, sarbaz1satr, sarbaz1sotoon, sarbaz1nam);
						bool vazir_easy_go = false;
						/////shomaresh tedad anasor jahathaye mojaz			

						for (shomarande; jahathayemojaz[shomarande] > 0; shomarande++) {

							if (meghdarharekatsarbaz1[shomarande] == 0)
								continue;
							vazir_easy_go = vazir_easy_for_khatar(sarbaz1satr, sarbaz1sotoon, khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz1[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

							if (vazir_easy_go)
							{
								yekharekat = true;
								easyallow = false;
								break;
							}
						}
					}
					if (sarbaz2darkhatar == true && yekharekat == false)
					{

						shomarande = 0;
						mohre_kojaye_vazire(&jahatmohresarbaz2, sarbaz2satr, sarbaz2sotoon, vazirsatr, vazirsotoon, map);
						vazir_easy_easy(&jahatmohresarbaz2, vazirsatr, vazirsotoon, jahathayemojaz, meghdarharekatsarbaz2, khodicount, khodi, sarbaz2satr, sarbaz2sotoon, sarbaz2nam);


						bool vazir_easy_go = false;

						/////shomaresh tedad anasor jahathaye mojaz							
						for (shomarande; jahathayemojaz[shomarande] > 0; shomarande++) {
							if (meghdarharekatsarbaz2[shomarande] == 0)
								continue;
							vazir_easy_go = vazir_easy_for_khatar(sarbaz2satr, sarbaz2sotoon, khodi, jahathayemojaz[shomarande], vazirsatr, vazirsotoon, vazirnammm, meghdarharekatsarbaz2[shomarande], setplayer, sarbaz1mojood, sarbaz2mojood, asbmojood, sarbaz1satr, sarbaz1sotoon, sarbaz2satr, sarbaz2sotoon, asbsatr, asbsotoon, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, sarbaz1nam, sarbaz2nam, asbnam);

							if (vazir_easy_go)
							{

								yekharekat = true;
								easyallow = false;
								break;
							}
						}
					}


					if (yekharekat == false && easyallow == true) {

						for (int jahatvazir2 = 0; jahatvazir2 < 8; jahatvazir2++) {
							//	bool vazir_easy(char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, bool khataryab)
							vazir_easyy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, true);
							//bool vazir_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* khatar, int* meghdarharekati = 0, bool khataryab = false)
							//بيايم بگيم  يه جهت  ساده تو قسمت ايزي الو تعريف کنيم
							//بعد بعد چک کردن 4 کن گو و ايف اصلي بگيم اگه ايف نقض شد 
							//تو السش اول جهت يکي اضافه بشه بعد دوباره وزير فور ايزي اجرا ببشه
							//تا زماني ک ايف اصليمون (4تا شرطه)ترو بشه
							//براي بقيه مهرهام همينکارو بکن
							int jahathayemojaz[6] = { 0 };

							//	cout << "\nvazirNew" << jahatvazir;
							if (sarbaz1harif)
								cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
							if (sarbaz2harif)
								cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
							if (asbharif)
								cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, vazirnewsatr, vazirnewsotoon);
							if (vazirharif)
								cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirnewsatr, vazirnewsotoon, map, vazirnammm);
							//	cout << cangofromasb;//5 mide
							//cin >> khatar;
							if (cangofromsarbaz1 == false || cangofromsarbaz2 == false || cangofromasb == false || cangofromvazir == false)
							{
								bool vazirmohafezdarad = false;
								if (sarbaz1mojood)
								{
									bool mohafezsarbaz = mohafez_darad(setplayer, 1, sarbaz1satr, sarbaz1sotoon, vazirnewsatr, vazirnewsotoon, map);
									if (mohafezsarbaz)
										vazirmohafezdarad = true;
								}//if sarbaz1mojood
								if (sarbaz2mojood)
								{
									bool mohafezsarbaz2 = mohafez_darad(setplayer, 1, sarbaz2satr, sarbaz2sotoon, vazirnewsatr, vazirnewsotoon, map);
									if (mohafezsarbaz2)
										vazirmohafezdarad = true;
								}//if sarbaz2mojood
								if (asbmojood)
								{
									bool mohafezasb = mohafez_darad(setplayer, 2, asbsatr, asbsotoon, vazirnewsatr, vazirnewsotoon, map);
									if (mohafezasb)
										vazirmohafezdarad = true;
								}//if asbmojood
								if (vazirmohafezdarad)
								{

									vazirdarkhatarast = vazir_dar_khatar_ast(setplayer, vazirsatr, vazirsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map);
									asbdarkhatarast = asb_dar_khatar_ast(setplayer, vazirsatr, vazirsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map);
									if (vazirdarkhatarast == false && asbdarkhatarast == false) {
										vazirforeasy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, false);
										if (vazirforeasy) {
											yekharekat = true;
											easyallow = false;
											break;
										}

									}
								}
							}


							if (vazir_easyy == true && cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true) {
								//cout << vazirnewsatr << vazirnewsotoon;
								//cin >> yekharekat;
								//bool vazir_easy(char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, bool khataryab)
								vazirforeasy = vazir_easy(&vz_t, setplayer, &jahatvazir, vazirsatr, vazirsotoon, vazirnammm, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map, khodi, &vazirnewsatr, &vazirnewsotoon, khodicount, false);
								if (vazirforeasy) {
									yekharekat = true;
									easyallow = false;
									break;
								}
							}
							else {
								//if (jahatvazir == 8)
								//vazirforeasy = false;

								jahatvazir++;
								//							vazirforeasy = false;
							}
						}//forjahatvazir

						 //}

						if (yekharekat == false && vazirforeasy)
						{

							yekharekat = true;
							easyallow = false;
							//cout << "vazireasybargharar";
						}
					}


					if (yekharekat == false)
					{
						//cout << "error";
						//1	cin >> yekharekat;
						//	cout << "falseeeee";
						//	cin >> yekharekat;
						/*
						//cout << yekharekat;
						cout << "falseeeeeeeeeeeeeeeeeeeeeeeeeeee";
						cin >> yekharekat;
						if (setplayer == '1')
						{
						if (sarbaz1mojood) {
						sarbaz1easy = sarbaz_2_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
						}
						if (sarbaz1easy)
						yekharekat = true;
						if (!sarbaz1easy&&yekharekat == false && sarbaz2mojood == true)
						sarbaz2easy = sarbaz_2_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
						if (sarbaz2easy)
						yekharekat = true;


						}
						else
						{
						if (sarbaz1mojood) {
						sarbaz1easy = sarbaz_easy(sarbaz1satr, sarbaz1sotoon, sarbaz1nam, map, khodi);
						}
						if (sarbaz1easy)
						yekharekat = true;
						if (!sarbaz1easy&&yekharekat == false && sarbaz2mojood == true)
						sarbaz2easy = sarbaz_easy(sarbaz2satr, sarbaz2sotoon, sarbaz2nam, map, khodi);
						if (sarbaz2easy)
						yekharekat = true;
						}
						if (yekharekat == false && asbmojood == true) {

						asbeasy = asb_easy(asbsatr, asbsotoon, asbnam, map, khodi, &khatar, false);
						}
						bool vazirreasy;
						if (asbeasy) {
						//cout << "asbhastesheasy";
						//cin >> asbeasy;
						yekharekat = true;
						}
						if (!asbeasy&&yekharekat == false && vazirmojood == true)

						vazirreasy = vazir_easy(vazirsatr, vazirsotoon, vazirnammm, map, khodi, 0, 0, false);
						if (!vazirreasy&&yekharekat == false) {
						//cout << "dg hich harekati nmishe kard";
						//cin>>vazireasy;
						}
						}
						*/

					}
					//}
				}
			}//if yekharekat==false

			 //in hamintori gozashtam doros shdo
			 //char ac;
			 //cin >> ac;
			 /* bool vazir_trial_func(int vazirsatr, int vazirsotoon, int jahatharekat, int meghdarharekati, int* satrvazirjadid, int* sotoonvazirjadid)
			 {
			 //1-bala 2-paein 3-chap 4-rast 5-balarast 6-balachap 7-paeinchap 8-paeinrast
			 switch (jahatharekat)
			 {
			 switch (jahatharekat)
			 {
			 case 1:
			 *satrvazirjadid = vazirsatr - meghdarharekati;
			 *sotoonvazirjadid = vazirsotoon;
			 break;


			 case 2:
			 vazirnewsatr = vazirsatr + meghdarharekati;
			 vazirnewsotoon = vazirsotoon;
			 break;
			 case 3:
			 vazirnewsatr = vazirsatr;
			 vazirnewsotoon = vazirsotoon - meghdarharekati;
			 break;
			 case 4:
			 vazirnewsatr = vazirsatr;
			 vazirnewsotoon = vazirsotoon + meghdarharekati;
			 break;
			 case 5:
			 vazirnewsatr = vazirsatr - meghdarharekati;
			 vazirnewsotoon = vazirsotoon + meghdarharekati;
			 break;
			 case 6:
			 vazirnewsatr = vazirsatr - meghdarharekati;
			 vazirnewsotoon = vazirsotoon - meghdarharekati;
			 break;
			 case 7:
			 vazirnewsatr = vazirsatr + meghdarharekati;
			 vazirnewsotoon = vazirsotoon - meghdarharekati;
			 break;
			 case 8:
			 vazirnewsatr = vazirsatr + meghdarharekati;
			 vazirnewsotoon = vazirsotoon + meghdarharekati;
			 }
			 }
			 */
		}
	}
}
bool vazir_dar_khatar_ast(char setplayer, int satrghararbeharekat, int sotoonghararbeharekat, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int vazirsatr, int vazirsotoon, char map[6][6])
{
	//تو این تابع دقیقا مکان فعلی مهره رو میدیم
	//بايد بگوئيم اگر سرباز يا اسب را تکان داديم چه بر سر وزير مي آيد اگر باعث وزير 
	//مي شود وزير حرکت کند تابع وزير در خطر است با کپي ارايه مپ و خالي کردن مهره اي  ک قصد حرکت دارد در نقشه
	//با استفاده از تابع چک ضرب وزير ک بجاي مقادير سطروستون جديد سطرستون خودش است چکک ميکنيم وزير درخطراست يا خير اگر درخطر باشد ترو ميدهد
	char copyofmap[6][6];
	for (int i = 0; i < 6; i++)//کپي عناصر مپ به کپي او مپ
		for (int j = 0; j < 5; j++)
			copyofmap[i][j] = map[i][j];
	copyofmap[satrghararbeharekat][sotoonghararbeharekat] = '-';
	char vazirnammm;
	if (setplayer == '1')
		vazirnammm = 'a';
	else
		vazirnammm = 'b';
	bool vz_s1_amn_ast = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirsatr, vazirsotoon, map, 'v');//v sarnamekhodie ke vazir o mikhaym checkkonim
	bool vz_s2_amn_ast = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirsatr, vazirsotoon, map, 'v');
	bool vz_as_amn_ast = checkzarbasb(asbharifsatr, asbharifsotoon, vazirsatr, vazirsotoon);
	bool vz_vz_amn_ast = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, copyofmap, vazirnammm);
	if (vz_s1_amn_ast == true && vz_s2_amn_ast == true && vz_as_amn_ast == true && vz_vz_amn_ast == true)
		return false;//yani vazir darkhatar nist
	else
		return true;
}
bool asb_dar_khatar_ast(int setplayer, int satrghararbeharekat, int sotoonghararbeharekat, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int asbsatr, int asbsotoon, char map[6][6])
{
	char copyofmap[6][6];
	for (int i = 0; i < 6; i++)//کپي عناصر مپ به کپي او مپ
		for (int j = 0; j < 5; j++)
			copyofmap[i][j] = map[i][j];
	copyofmap[satrghararbeharekat][sotoonghararbeharekat] = '-';
	char asbnam;
	if (setplayer == '1')
		asbnam = 'e';
	else
		asbnam = 'f';
	//براي وزير فقط براي وزيره حريفه ک چک ميکنه اما بايد همه مهرهاي حريف چک کنه
	bool asb_s1_amn_ast = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbsatr, asbsotoon, map, 'o');//o sarnamekhodie ke asb o mikhaym checkkonim
	bool asb_s2_amn_ast = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbsatr, asbsotoon, map, 'o');
	bool asb_as_amn_ast = checkzarbasb(asbharifsatr, asbharifsotoon, asbsatr, asbsotoon);
	bool asb_vz_amn_ast = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, copyofmap, asbnam);
	if (asb_s1_amn_ast == true && asb_s2_amn_ast == true && asb_as_amn_ast == true && asb_vz_amn_ast == true)
		return false;//yani asb darkhatar nist
	else
		return true;
}
void aya_mitavanad_sade_harekat(char setplayer, int noemohre, int satrmohre, int sotoonmohre, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon, int vazirsatr, int vazirsotoon, bool* aya_mohre_mohafez_s1, bool* aya_mohre_mohafez_s2, bool* aya_mohre_mohafez_asb, bool* aya_mohre_mohafez_vazir, char map[6][6])
{
	/*
	بياييم بگوئيم درحرکت ساده هر مهره خودي اگر اين مهره 1- محافظ مهره اي باشد و با حرکتش محافظتش از بين برود از حرکت ساده آن مهره صرفنظر شود
	يعني:
	يک تابع چک کند ک هر مهره محافظ چه مهره ايست سپس چک کند درمسيرجديد مهره آيا محافظتش برقرار است يا خير
	*/
	//noe mohre 1sARBAZ 2 ASB 3 VAZIR
	*aya_mohre_mohafez_s1 = mohafez_darad(setplayer, noemohre, satrmohre, sotoonmohre, sarbaz1satr, sarbaz1sotoon, map);
	*aya_mohre_mohafez_s2 = mohafez_darad(setplayer, noemohre, satrmohre, sotoonmohre, sarbaz2satr, sarbaz2sotoon, map);
	*aya_mohre_mohafez_asb = mohafez_darad(setplayer, noemohre, satrmohre, sotoonmohre, asbsatr, asbsotoon, map);
	*aya_mohre_mohafez_vazir = mohafez_darad(setplayer, noemohre, satrmohre, sotoonmohre, vazirsatr, vazirsotoon, map);
}
bool mohafez_ghabelzadane(char sarnammohremohafez, int satrmohreavvali, int sotoonmohreavvali, char setplayer, int satrmohafez, int sotoonmohafez, int satrmahaljadid, int sotoonmahaljadid, char map[6][6], int sarbaz1harif,
	int sarbaz2harif, int asbharif, int  vazirharif, int  sarbaz1harifsatr, int sarbaz1harifsotoon, int  sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon
	, int vazirharifsatr, int vazirharifsotoon)
{
	/* in tabe check mikone ke aya mohre khodi ma mitune mohre khodi dgio to mahal jadidesh
	bezane(yani mitune azashmohafezat kone) pas ba dadan ettelat khodi be tavabecheckzarbha
	oomadim goftim agar checkzarbha false bood(chon age bezane false mide) return true kon
	yani mohafez darad
	mohafezchist;//1 sarbaz 2 asb 3vazir
	*/
	if ((satrmahaljadid == -1 && sotoonmahaljadid == -1) || (satrmahaljadid>5 || sotoonmahaljadid>5))
		return false;
	bool mohafezsarbaz = true, mohafezasb = true, mohafezvazir = true;
	char copyofmap[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			copyofmap[i][j] = map[i][j];

	copyofmap[satrmahaljadid][sotoonmahaljadid] = sarnammohremohafez;
	copyofmap[satrmohafez][sotoonmohafez] = '-';
	copyofmap[satrmohreavvali][sotoonmohreavvali] = '-';
	//setplayero baraks mikonim chon vaghti mire to checkzarbsarbaz
	//mohrekhodi harife aztarafi setplayer khodesho migire va darjahat moghabel check mikone 
	//bayad setplayero baraks konim ta darjahat dorost checkkone
	bool ayamohafez_ghabelzadane = checkzarb(setplayer, satrmahaljadid, sotoonmahaljadid, sarnammohremohafez, sarbaz1harif,
		sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon
		, vazirharifsatr, vazirharifsotoon, copyofmap);

	if (ayamohafez_ghabelzadane == false)//checkzarb false bashe yani harif mitune bezane
		return true;
	/*if (setplayer == '1')
	setplayer = '2';
	else
	setplayer = '1';
	if (satrmohafez == satrmahaljadid&&sotoonmohafez == sotoonmahaljadid)
	return false;//baraye tabe bala ino neveshtam
	switch (mohafezchist)
	{
	case 1:
	mohafezsarbaz = checkzarbsarbaz(setplayer, satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, map, 's');
	if (mohafezsarbaz == false)//chon age bezane false mide
	return true;
	break;
	case 2:
	mohafezasb = checkzarbasb(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid);
	if (!mohafezasb)
	return true;
	break;
	case 3:
	mohafezvazir = checkzarbvazir(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, map, 's');
	if (!mohafezvazir)
	return true;
	break;
	}
	return false;
	*/
	return false;
}

bool mohafez_darad(char setplayer, int mohafezchist, int satrmohafez, int sotoonmohafez, int satrmahaljadid, int sotoonmahaljadid, char map[6][6])
{
	/* in tabe check mikone ke aya mohre khodi ma mitune mohre khodi dgio to mahal jadidesh
	bezane(yani mitune azashmohafezat kone) pas ba dadan ettelat khodi be tavabecheckzarbha
	oomadim goftim agar checkzarbha false bood(chon age bezane false mide) return true kon
	yani mohafez darad
	mohafezchist;//1 sarbaz 2 asb 3vazir
	*/
	bool mohafezsarbaz = true, mohafezasb = true, mohafezvazir = true;
	//setplayero baraks mikonim chon vaghti mire to checkzarbsarbaz
	//mohrekhodi harife aztarafi setplayer khodesho migire va darjahat moghabel check mikone 
	//bayad setplayero baraks konim ta darjahat dorost checkkone
	if (setplayer == '1')
		setplayer = '2';
	else
		setplayer = '1';
	if (satrmohafez == satrmahaljadid&&sotoonmohafez == sotoonmahaljadid)
		return false;//baraye tabe bala ino neveshtam
	switch (mohafezchist)
	{
	case 1:
		mohafezsarbaz = checkzarbsarbaz(setplayer, satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, map, 's');
		if (mohafezsarbaz == false)//chon age bezane false mide
			return true;
		break;
	case 2:
		mohafezasb = checkzarbasb(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid);
		if (!mohafezasb)
			return true;
		break;
	case 3:
		mohafezvazir = checkzarbvazir(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, map, 's');
		if (!mohafezvazir)
			return true;
		break;
	}
	return false;
}

bool mohafez_darad_2(int vazirnewsatr, int vazirnewsotoon, char setplayer, int mohafezchist, int satrmohafez, int sotoonmohafez, int satrmahaljadid, int sotoonmahaljadid, char map[6][6], char vazirnammm)
{
	//این محافظ دارد برای وزیرایزی فور خطره 
	/* in tabe check mikone ke aya mohre khodi ma mitune mohre khodi dgio to mahal jadidesh
	bezane(yani mitune azashmohafezat kone) pas ba dadan ettelat khodi be tavabecheckzarbha
	oomadim goftim agar checkzarbha false bood(chon age bezane false mide) return true kon
	yani mohafez darad
	mohafezchist;//1 sarbaz 2 asb 3vazir
	*/
	bool mohafezsarbaz = true, mohafezasb = true, mohafezvazir = true;
	//setplayero baraks mikonim chon vaghti mire to checkzarbsarbaz
	//mohrekhodi harife aztarafi setplayer khodesho migire va darjahat moghabel check mikone 
	//bayad setplayero baraks konim ta darjahat dorost checkkone
	char copyofmap[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			copyofmap[i][j] = map[i][j];
	copyofmap[satrmohafez][sotoonmohafez] = '-';
	copyofmap[vazirnewsatr][vazirnewsotoon] = vazirnammm;
	satrmohafez = vazirnewsatr;
	sotoonmohafez = vazirnewsotoon;
	if (setplayer == '1')
		setplayer = '2';
	else
		setplayer = '1';
	if (satrmohafez == satrmahaljadid&&sotoonmohafez == sotoonmahaljadid)
		return false;//baraye tabe bala ino neveshtam
	switch (mohafezchist)
	{
	case 1:
		mohafezsarbaz = checkzarbsarbaz(setplayer, satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, copyofmap, 's');
		if (mohafezsarbaz == false)//chon age bezane false mide
			return true;
		break;
	case 2:
		mohafezasb = checkzarbasb(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid);
		if (!mohafezasb)
			return true;
		break;
	case 3:
		mohafezvazir = checkzarbvazir(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, copyofmap, 's');
		if (!mohafezvazir)
			return true;
		break;
	}
	return false;
}
void aya_zadan_ghable_farar_amn_ast(int harifsatr, int harifsotoon, char setplayer, int mohafezchist, int satrmohrekhodi, int sotoonmohrekhodi, char map[6][6], char copyofmap1[6][6], char nammohre)
{
	//این محافظ دارد برای وزیرایزی فور خطره 
	/* in tabe check mikone ke aya mohre khodi ma mitune mohre khodi dgio to mahal jadidesh
	bezane(yani mitune azashmohafezat kone) pas ba dadan ettelat khodi be tavabecheckzarbha
	oomadim goftim agar checkzarbha false bood(chon age bezane false mide) return true kon
	yani mohafez darad
	mohafezchist;//1 sarbaz 2 asb 3vazir
	*/
	bool mohafezsarbaz = true, mohafezasb = true, mohafezvazir = true;
	//setplayero baraks mikonim chon vaghti mire to checkzarbsarbaz
	//mohrekhodi harife aztarafi setplayer khodesho migire va darjahat moghabel check mikone 
	//bayad setplayero baraks konim ta darjahat dorost checkkone

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			copyofmap1[i][j] = map[i][j];
	copyofmap1[satrmohrekhodi][sotoonmohrekhodi] = '-';
	copyofmap1[harifsatr][harifsotoon] = nammohre;
	//حالا اونجا تابع چک ضرب با کپی او مپ چک کن حواست باشه با کپی او مپ اینجا نه مپ اصلی 
	//hamoon satrosotoon mohreharifie ke mishe zad
	/*satrmohafez = asbnewsatr;
	sotoonmohafez = asbnewsotoon;
	if (setplayer == '1')
	setplayer = '2';
	else
	setplayer = '1';
	if (satrmohafez == satrmahaljadid&&sotoonmohafez == sotoonmahaljadid)
	return false;//baraye tabe bala ino neveshtam
	switch (mohafezchist)
	{
	case 1:
	mohafezsarbaz = checkzarbsarbaz(setplayer, satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, copyofmap, 's');
	if (mohafezsarbaz == false)//chon age bezane false mide
	return true;
	break;
	case 2:
	mohafezasb = checkzarbasb(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid);
	if (!mohafezasb)
	return true;
	break;
	case 3:
	mohafezvazir = checkzarbvazir(satrmohafez, sotoonmohafez, satrmahaljadid, sotoonmahaljadid, copyofmap, 's');
	if (!mohafezvazir)
	return true;
	break;
	}
	return false;
	*/
}

bool is_our(char sarnam, char* khodi)
{
	//	cout << "\nsarnam:" << sarnam << endl;
	for (int i = 0; i < 4; i++)//badanaz sizeof estefade kon
	{
		if (khodi[i] == sarnam)
		{
			return false;
		}

	}


}
bool sarbaz_can_move(char setplayer, int satr, int sotoon, char map[6][6])
{

	if (setplayer == '2') {
		if (map[satr - 1][sotoon] != '-')//ESHTEBAH INE KE BEJAYE INKE SATRO SOTOON KHODETO BEDI MALE HARIF MIDI
			return false;
	}
	if (setplayer == '1') {
		if (map[satr + 1][sotoon] != '-')//ESHTEBAH INE KE BEJAYE INKE SATRO SOTOON KHODETO BEDI MALE HARIF MIDI
			return false;
	}

	return true;
}
bool sarbaz_move(int satr, int sotoon, char map[6][6])
{
	if (satr - 1 < 0)
		return false;
	//if (map[satr - 1][sotoon] != '-')//ESHTEBAH INE KE BEJAYE INKE SATRO SOTOON KHODETO BEDI MALE HARIF MIDI
	//	return false;
	else
		return true;
}
bool sarbaz_2_move(int satr, int sotoon, char map[6][6])
{
	if (satr + 1 > 5)
		return false;
	//if (map[satr + 1][sotoon] != '-')// sarbaz mitune jolosham chizi bashe bezane ghalate in harfa->ESHTEBAH INE KE BEJAYE INKE SATRO SOTOON KHODETO BEDI MALE HARIF MIDI
	//		return false;
	else
		return true;
}
bool sarbaz_2_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi)//is_our dare
{

	if (sarbaz_2_move(satr, sotoon, map))
	{

		if (is_our(map[satr + 1][sotoon], khodi)) {//check mikone ke mohre ma e ya na

			if (map[satr + 1][sotoon] == '-') {
				map[satr + 1][sotoon] = sarnam;
				map[satr][sotoon] = '-';
				return true;
			}
			return false;
		}
	}
	else
		return false;

	return false;

}
bool sarbaz_easy(int satr, int sotoon, char sarnam, char map[6][6], char* khodi)//is_our dare
{

	if (sarbaz_move(satr, sotoon, map))
	{

		if (is_our(map[satr - 1][sotoon], khodi)) {//check mikone ke mohre ma e ya na
			if (map[satr - 1][sotoon] == '-') {
				map[satr - 1][sotoon] = sarnam;
				map[satr][sotoon] = '-';
				return true;
			}
			return false;
		}
	}
	else
		return false;

	return false;

}

bool asb_easy(int* jahat, int satr, int sotoon, char sarnam, char map[6][6], char* khodi, int* asbnewsatr, int*asbnewsotoon, bool khataryab)//is_our dare
{
	//1:2balachap 2:2balarast 3-2paeinchap 4-2paeinrast 5-1balachap 6-1balarast 7-1paeinchap 8-1paeinrast
	//be khatar 10 bedi yani false in tabe
	//cout << "Jahat" << *jahat<<endl;
	//	cout << *jahat;
	for (*jahat; *jahat < 9; jahat++) {
		if (*jahat == 1) {

			if (satr - 2 >= 0 && sotoon - 1 >= 0)
			{

				if (is_our(map[satr - 2][sotoon - 1], khodi)) {
					if (map[satr - 2][sotoon - 1] == '-') {
						if (khataryab == true) {
							*asbnewsatr = satr - 2;
							*asbnewsotoon = sotoon - 1;
							return true;//hamintori gozashtam ta tabetamooom she
						}
						//	cout << "sana";
						map[satr - 2][sotoon - 1] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		else if (*jahat == 2) {
			if (satr - 2 >= 0 && sotoon + 1 < 6)
			{
				if (is_our(map[satr - 2][sotoon + 1], khodi)) {
					if (map[satr - 2][sotoon + 1] == '-') {
						if (khataryab == true) {
							*asbnewsatr = satr - 2;
							*asbnewsotoon = sotoon + 1;
							return true;
						}
						map[satr - 2][sotoon + 1] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		else if (*jahat == 3) {

			if (satr + 2 < 6 && sotoon - 1 >= 0)
			{
				if (is_our(map[satr + 2][sotoon - 1], khodi)) {

					if (map[satr + 2][sotoon - 1] == '-') {
						if (khataryab == true) {
							*asbnewsatr = satr + 2;
							*asbnewsotoon = sotoon - 1;
							//	cout << "khalas";
							return true;
						}
						map[satr + 2][sotoon - 1] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		else if (*jahat == 4) {
			//	cout << "sa" << satr << sotoon;
			if (satr + 2 < 6 && sotoon + 1 < 6)
			{
				if (is_our(map[satr + 2][sotoon + 1], khodi)) {
					if (map[satr + 2][sotoon + 1] == '-') {

						if (khataryab == true) {
							*asbnewsatr = satr + 2;
							*asbnewsotoon = sotoon + 1;
							return true;//baraye vaziram haminkaro kon
						}
						map[satr + 2][sotoon + 1] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;

				}
				else
					continue;
			}
		}
		else if (*jahat == 5) {
			//	cout << "salam ey irani";
			if (satr - 1 >= 0 && sotoon - 2 >= 0)
			{

				if (is_our(map[satr - 1][sotoon - 2], khodi)) {

					if (map[satr - 1][sotoon - 2] == '-') {

						if (khataryab == true) {
							*asbnewsatr = satr - 1;
							*asbnewsotoon = sotoon - 2;
							return true;
						}
						map[satr - 1][sotoon - 2] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		else if (*jahat == 6) {
			if (satr - 1 >= 0 && sotoon + 2 < 6)
			{
				if (is_our(map[satr - 1][sotoon + 2], khodi)) {

					if (map[satr - 1][sotoon + 2] == '-') {
						if (khataryab == true) {
							*asbnewsatr = satr - 1;
							*asbnewsotoon = sotoon + 2;
							return true;
						}
						map[satr - 1][sotoon + 2] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		else if (*jahat == 7) {
			if (satr + 1 < 6 && sotoon - 2 >= 0)
			{
				if (is_our(map[satr + 1][sotoon - 2], khodi)) {
					if (map[satr + 1][sotoon - 2] == '-') {
						if (khataryab == true) {
							*asbnewsatr = satr + 1;
							*asbnewsotoon = sotoon - 2;
							return true;
						}
						map[satr + 1][sotoon - 2] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}
				else
					continue;
			}
		}
		else if (*jahat == 8) {
			if (satr + 1 < 6 && sotoon + 2 < 6)
			{
				if (is_our(map[satr + 1][sotoon + 2], khodi)) {
					if (map[satr + 1][sotoon + 2] == '-') {
						if (khataryab == true) {
							*asbnewsatr = satr + 1;
							*asbnewsotoon = sotoon + 2;
							return true;
						}
						map[satr + 1][sotoon + 2] = sarnam;
						map[satr][sotoon] = '-';
						return true;
					}
					else
						continue;
				}

				continue;
			}
		}
		else
		{
			return false;
		}

	}//for
}
bool mohre_kojaye_vazire(int* jahatmohrekhodi, int satrmohre, int sotoonmohre, int satrvazir, int sotoonvazir, char map[6][6])
{
	//jahate bala(yani vazirrrrrrrrrrrr mirebala)
	//to jahate 1 ta 4 == bakhsh dovvom o hazf kardimmm
	int m = 0;
	if (satrmohre < satrvazir&&sotoonmohre == sotoonvazir) {
		*jahatmohrekhodi = 1;
	}
	m = 0;//paein
	if (satrmohre > satrvazir&&sotoonmohre == sotoonvazir) {
		*jahatmohrekhodi = 2;
	}
	m = 0;//chap
	if (sotoonmohre < sotoonvazir&&satrmohre == satrvazir) {
		*jahatmohrekhodi = 3;
	}
	m = 0;//rast
	if (sotoonmohre >sotoonvazir&&satrmohre == satrvazir) {
		*jahatmohrekhodi = 4;

	}
	m = 0;//balarast
	while (satrvazir - (m + 1) >= 0 && sotoonvazir + (m + 1) <= 5 && satrvazir - (m + 1) >= satrmohre&&sotoonvazir + (m + 1) <= sotoonmohre)
	{
		m++;
	}//while
	if (map[satrvazir - m][sotoonvazir + m] == map[satrmohre][sotoonmohre])
	{
		*jahatmohrekhodi = 5;
		return true;//faghat gozashtm ke tamoomshe
	}

	m = 0;//balachap
	while (satrvazir - (m + 1) >= 0 && sotoonvazir - (m + 1) >= 0 && satrvazir - (m + 1) >= satrmohre&&sotoonvazir - (m + 1) >= sotoonmohre)
	{
		m++;
	}
	if (map[satrvazir - m][sotoonvazir + m] == map[satrmohre][sotoonmohre])
	{
		*jahatmohrekhodi = 6;
		return true;
	}
	m = 0;//paeinchap
	while (satrvazir + (m + 1) <= 5 && sotoonvazir - (m + 1) >= 0 && satrvazir + m + 1 <= sotoonmohre&&sotoonvazir - (m + 1) >= sotoonmohre)
	{
		m++;
	}
	if (map[satrvazir + m][sotoonvazir - m] == map[satrmohre][sotoonmohre])
	{
		*jahatmohrekhodi = 7;
		return true;
	}
	m = 0;//paeinrast
	while (satrvazir + (m + 1) >= 5 && sotoonvazir + m + 1 <= 5 && satrvazir + m + 1 <= satrmohre&&sotoonvazir + m + 1 <= sotoonmohre)
	{
		m++;
	}
	if (map[satrvazir + m][sotoonvazir + m] == map[satrmohre][sotoonmohre]) {
		*jahatmohrekhodi = 8;
		return true;
	}
	if (satrmohre > satrvazir && (sotoonmohre<sotoonvazir))
		*jahatmohrekhodi = 9;//237//halati ke mohre zire vazire ba sharayet bala237
	if (satrmohre > satrvazir&&sotoonmohre > sotoonvazir)
		*jahatmohrekhodi = 11;//248
	if (satrmohre < satrvazir && (sotoonmohre<sotoonvazir))
		*jahatmohrekhodi = 12;//136
	if (satrmohre<satrvazir&&sotoonmohre>sotoonvazir)
		*jahatmohrekhodi = 10;//3769 145
}
void vazir_easy_easy(int *jahat, int satr, int sotoon, int jahathayemojaz[], int meghdarharekat[], int khodicount, char* khodi, int satrmohre, int sotoonmohre, char sarnammohre)
{//jahat inja jahat mohre khodie!!!!!!!
 //satrmohre=satre mohreike be tabe rad mishe
 //satr=satrvazir
 //sotoon=sotoonvazir
 //biaym begim agar mohre khodi balaye vazir bood  jahat==1 anjamshe
 //hala jahathaye mojazo darim va tak tak injahatharo baraye raftan vazir
 //check mikonim
	int m = 0;
	//1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
	//tabdil mohrehaye dotaei az gh be c o d
	char* khodi2 = khodi;
	for (int i = 0; i < khodicount; i++)
		if (khodi2[i] == 'g' || khodi2[i] == 'h')
			khodi[i] = 'c';
		else if (khodi2[i] == 'k' || khodi2[i] == 'l')
			khodi2[i] = 'd';

	for (*jahat; *jahat < 13; jahat++)
	{

		int v = 0;
		if (*jahat == 1)//bala
		{
			if (map[satr - 1][sotoon] == sarnammohre)
			{
				jahathayemojaz[0] = 2;
				jahathayemojaz[1] = 3;
				jahathayemojaz[2] = 4;
				jahathayemojaz[3] = 5;
				jahathayemojaz[4] = 6;
			}

			for (int counter = 0; counter < khodicount; counter++)
			{

				for (v = 0; map[satr - (v + 1)][sotoon] == '-'; v++) {
					//					cout << "\salaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaan" << v;
					if (map[satr - (v + 2)][sotoon] == khodi2[counter]) {
						//	cout << "v" << v;
						//if (map[satr - (m + 1)][sotoon] == khodi2[counter]) {
						jahathayemojaz[0] = 2;
						jahathayemojaz[1] = 3;
						jahathayemojaz[2] = 4;
						jahathayemojaz[3] = 5;
						jahathayemojaz[4] = 6;

					}

				}//forcounter
			}
			if (jahathayemojaz[0] == 2) {
				m = 0;
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 3) {
				m = 0;
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 4) {
				m = 0;
				while (sotoon + (m + 1) <= 5 && sotoon + (m) <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}
			if (jahathayemojaz[3] == 5) {
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon + (m + 1) <= 5 && satr - (m) >= satrmohre&&sotoon + (m) <= sotoonmohre)
				{
					m++;
				}//while
				if (m == 0)
					jahathayemojaz[3] = 0;
				else
					meghdarharekat[3] = m;
			}
			if (jahathayemojaz[4] == 6) {
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon - (m + 1) >= 0 && satr - (m) >= satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[4] = 0;
				else
					meghdarharekat[4] = m;
			}

			break;
		}//if jahat1


		if (*jahat == 2)//paein
		{
			if (map[satr + 1][sotoon] == sarnammohre)
			{
				jahathayemojaz[0] = 3;
				jahathayemojaz[1] = 4;
				jahathayemojaz[2] = 7;
				jahathayemojaz[3] = 8;
			}
			int v = 0;
			for (int counter = 0; counter < khodicount; counter++)
			{
				for (v = 0; map[satr + (v + 1)][sotoon] == '-'; v++) {
					//cout << "\n" << v;
					//cout << satr << sotoon<<khodi2[counter];
					if (map[satr + (v + 2)][sotoon] == khodi2[counter]) {

						//cout << "v" << v;
						jahathayemojaz[0] = 3;
						jahathayemojaz[1] = 4;
						jahathayemojaz[2] = 7;
						jahathayemojaz[3] = 8;

					}
				}//forcounter
			}
			if (jahathayemojaz[0] == 3)
			{
				m = 0;
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 4)
			{
				m = 0;
				while (sotoon + (m + 1) <= 5 && sotoon + (m) <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 7)
			{
				m = 0;
				while (satr + (m + 1) <= 5 && sotoon - (m + 1) >= 0 && satr + m <= satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}
			if (jahathayemojaz[3] == 8)
			{
				m = 0;
				while (satr + (m + 1) >= 5 && sotoon + m + 1 <= 5 && satr + m <= satrmohre&&sotoon + m <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[3] = 0;
				else
					meghdarharekat[3] = m;
			}
			break;

		}
		if (*jahat == 3)//chap
		{
			int v = 0;
			if (map[satr][sotoon - 1] == sarnammohre)
			{
				jahathayemojaz[0] = 1;
				jahathayemojaz[1] = 2;
				jahathayemojaz[2] = 4;
				jahathayemojaz[3] = 6;
				jahathayemojaz[4] = 7;
			}
			for (int counter = 0; counter < khodicount; counter++)
			{
				for (v = 0; map[satr][sotoon - (v + 1)] == '-'; v++) {
					//	cout << "\n" << v;
					if (map[satr][sotoon - (v + 2)] == khodi2[counter]) {
						//	cout << "v" << v;
						jahathayemojaz[0] = 1;
						jahathayemojaz[1] = 2;
						jahathayemojaz[2] = 4;
						jahathayemojaz[3] = 6;
						jahathayemojaz[4] = 7;
						//*meghdarharekat = m + 1;
						break;
					}
					else
						continue;


				}
			}//forcounter
			if (jahathayemojaz[0] == 1) {
				m = 0;
				while (satr - (m + 1) >= 0 && satr - (m) >= satrmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 2) {

				m = 0;
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 4) {
				m = 0;
				while (sotoon + (m + 1) <= 5 && sotoon + (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;

			}
			if (jahathayemojaz[3] == 6) {
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon - (m + 1) >= 0 && satr - (m) >= satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[3] = 0;
				else
					meghdarharekat[3] = m;

			}
			if (jahathayemojaz[4] == 7) {
				m = 0;
				while (satr + (m + 1) <= 5 && sotoon - (m + 1) >= 0 && satr + m <= satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[4] = 0;
				else
					meghdarharekat[4] = m;

			}
			break;
		}//if jahat3
		if (*jahat == 11)
		{
			int v = 0;
			for (int counter = 0; counter < khodicount; counter++)
			{
				jahathayemojaz[0] = 2;
				jahathayemojaz[1] = 4;
				jahathayemojaz[2] = 8;


			}

			if (jahathayemojaz[0] == 2)
			{
				m = 0;
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else

					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 4)
			{
				m = 0;
				while (sotoon + (m + 1) <= 5 && sotoon + (m) <= sotoonmohre)
				{
					//	cout << sotoon << sotoonmohre;
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 8)
			{
				m = 0;
				while (satr + (m + 1) >= 5 && sotoon + m + 1 <= 5 && satr + m <= satrmohre&&sotoon + m <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}
			break;
		}//firstfor
		 //if9
		if (*jahat == 9)
		{
			int v = 0;
			for (int counter = 0; counter < khodicount; counter++)
			{

				jahathayemojaz[0] = 2;
				jahathayemojaz[1] = 3;
				jahathayemojaz[2] = 7;

			}
			if (jahathayemojaz[0] == 2)
			{

				m = 0;
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else

					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 3)
			{
				m = 0;
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 7)
			{
				m = 0;
				while (satr + (m + 1) <= 5 && sotoon - (m + 1) >= 0 && satr + m < satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}


			break;
		}//if11
		if (*jahat == 10)
		{
			int v = 0;
			for (int counter = 0; counter < khodicount; counter++)
			{


				jahathayemojaz[0] = 1;
				jahathayemojaz[1] = 4;
				jahathayemojaz[2] = 5;

			}
			if (jahathayemojaz[0] == 1) {
				m = 0;
				while (satr - (m + 1) >= 0 && satr - (m) >= satrmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else

					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 4)
			{
				m = 0;
				while (sotoon + (m + 1) <= 5 && sotoon + (m) <= sotoonmohre)
				{
					//cout << sotoon << sotoonmohre;
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else

					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 5)
			{
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon + (m + 1) <= 5 && satr - (m) >= satrmohre&&sotoon + (m) <= sotoonmohre)
				{
					m++;
				}//while
				if (m == 0)
					jahathayemojaz[2] = 0;
				else

					meghdarharekat[2] = m;
			}


			break;
		}//if10
		if (*jahat == 12)
		{
			int v = 0;
			for (int counter = 0; counter < khodicount; counter++)
			{

				jahathayemojaz[0] = 1;
				jahathayemojaz[1] = 3;
				jahathayemojaz[2] = 6;


			}
			if (jahathayemojaz[0] == 1) {
				m = 0;
				while (satr - (m + 1) >= 0 && satr - (m) >= satrmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 3)
			{
				m = 0;
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 6)
			{
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon - (m) >= 0 && satr - (m) >= satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}


			break;
		}//if12
		if (*jahat == 4)//rast
		{
			int v = 0;
			if (map[satr][sotoon + 1] == sarnammohre)
			{
				jahathayemojaz[0] = 1;
				jahathayemojaz[1] = 2;
				jahathayemojaz[2] = 3;
				jahathayemojaz[3] = 5;
				jahathayemojaz[4] = 8;
			}
			for (int counter = 0; counter < khodicount; counter++)
			{
				for (v = 0; map[satr][sotoon + (v + 1)] == '-'; v++) {
					//cout << "\n" << v;
					if (map[satr][sotoon + (v + 2)] == khodi2[counter]) {
						//	cout << "v" << v;

						jahathayemojaz[0] = 1;
						jahathayemojaz[1] = 2;
						jahathayemojaz[2] = 3;
						jahathayemojaz[3] = 5;
						jahathayemojaz[4] = 8;

					}
					else
						continue;

				}
			}
			//forcounter
			if (jahathayemojaz[0] == 1) {
				m = 0;
				while (satr - (m + 1) >= 0 && satr - (m) >= satrmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 2)
			{
				m = 0;
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 3)
			{
				m = 0;
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}
			if (jahathayemojaz[3] == 5)
			{
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon + (m) <= 5 && satr - (m) >= satrmohre&&sotoon + (m) <= sotoonmohre)
				{
					m++;
				}//while
				if (m == 0)
					jahathayemojaz[3] = 0;
				else
					meghdarharekat[3] = m;
			}
			if (jahathayemojaz[4] == 8)
			{
				m = 0;
				while (satr + (m + 1) >= 5 && sotoon + m <= 5 && satr + m <= satrmohre&&sotoon + m <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[4] = 0;
				else
					meghdarharekat[4] = m;
			}
			break;
		}

		if (*jahat == 5)//BALARAST
		{
			int v = 0;
			if (map[satr - 1][sotoon + 1] == sarnammohre)
			{
				jahathayemojaz[0] = 1;
				jahathayemojaz[1] = 4;
				jahathayemojaz[2] = 5;

			}
			for (int counter = 0; counter < khodicount; counter++)
			{
				for (v = 0; map[satr - (v + 1)][sotoon + (v + 1)] == '-'; v++) {
					//	cout << "\n" << v;
					if (map[satr - (v + 2)][sotoon + (v + 2)] == khodi2[counter]) {
						//cout << "v" << v;

						jahathayemojaz[0] = 1;
						jahathayemojaz[1] = 4;
						jahathayemojaz[2] = 5;


					}
				}
			}//forcounter
			if (jahathayemojaz[0] == 1)
			{
				m = 0;
				while (satr - (m + 1) >= 0 && satr - (m) >= satrmohre)
				{
					m++;

				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else

					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 4)
			{
				m = 0;
				while (sotoon + (m + 1) <= 5 && sotoon + (m) <= sotoonmohre)
				{
					//cout << sotoon << sotoonmohre;
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 5) {
				m = 0;//m+1 mikonim ta bakhodesh eshtebah nagirim
				while (satr - (m + 1) >= 0 && sotoon + (m + 1) <= 5 && satr - (m) >= satrmohre&&sotoon + (m) <= sotoonmohre)
				{
					m++;
				}//while
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}

			break;
		}//if jahat5
		if (*jahat == 6)//BALAchap
		{
			int v = 0;
			if (map[satr - 1][sotoon - 1] == sarnammohre)
			{
				jahathayemojaz[0] = 1;
				jahathayemojaz[1] = 3;
				jahathayemojaz[2] = 6;
			}
			for (int counter = 0; counter < khodicount; counter++)
			{

				for (v = 0; map[satr - (v + 1)][sotoon - (v + 1)] == '-'; v++) {
					//cout << "\n" << v;
					if (map[satr - (v + 2)][sotoon - (v + 2)] == khodi2[counter]) {
						//	cout << "v" << v;

						jahathayemojaz[0] = 1;
						jahathayemojaz[1] = 3;
						jahathayemojaz[2] = 6;
					}
				}
			}//forcounter
			if (jahathayemojaz[0] == 1)
			{
				m = 0;
				while (satr - (m + 1) >= 0 && satr - (m) >= satrmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 3) {
				m = 0;
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 6)
			{
				m = 0;
				while (satr - (m + 1) >= 0 && sotoon - (m + 1) >= 0 && satr - (m) >= satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}

			break;
			//if jahat6

		}

		if (*jahat == 7)//paeinchap
		{
			int v = 0;
			if (map[satr + 1][sotoon - 1] == sarnammohre)
			{
				jahathayemojaz[0] = 2;
				jahathayemojaz[1] = 3;
				jahathayemojaz[2] = 7;
			}
			for (int counter = 0; counter < khodicount; counter++)
			{
				for (v = 0; map[satr + (v + 1)][sotoon - (v + 1)] == '-'; v++) {
					//cout << "\n" << v;
					if (map[satr + (v + 2)][sotoon - (v + 2)] == khodi2[counter]) {
						//cout << "v" << v;
						jahathayemojaz[0] = 2;
						jahathayemojaz[1] = 3;
						jahathayemojaz[2] = 7;
					}
				}//forcounter
			}
			m = 0;
			if (jahathayemojaz[0] == 2) {
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;
			}
			if (jahathayemojaz[1] == 3)
			{
				while (sotoon - (m + 1) >= 0 && sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[1] = m;
			}
			if (jahathayemojaz[2] == 7)
			{
				while (satr + (m + 1) <= 5 && sotoon - (m + 1) >= 0 && satr + m < satrmohre&&sotoon - (m) >= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[2] = m;
			}
			break;
		}//if jahat7

		if (*jahat == 8)//paeinrast
		{
			int v = 0;
			if (map[satr + 1][sotoon + 1] == sarnammohre)
			{
				jahathayemojaz[0] = 2;
				jahathayemojaz[1] = 4;
				jahathayemojaz[2] = 8;
			}
			m = 0;
			for (int counter = 0; counter < khodicount; counter++)
			{
				for (v = 0; map[satr + (v + 1)][sotoon + (v + 1)] == '-'; v++) {
					//cout << "\n" << v;
					if (map[satr + (v + 2)][sotoon + (v + 2)] == khodi2[counter]) {
						//	cout << "v" << v;
						jahathayemojaz[0] = 2;
						jahathayemojaz[1] = 4;
						jahathayemojaz[2] = 8;

					}
				}//forcounter
			}
			if (jahathayemojaz[0] == 2) {
				while (satr + m + 1 <= 5 && satr + m <= satrmohre)//be meghdari biad paein
																  //kesatra barabarshe
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[0] = 0;
				else
					meghdarharekat[0] = m;

			}
			m = 0;
			if (jahathayemojaz[1] == 4) {
				while (sotoon + (m + 1) <= 5 && sotoon + (m) <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[1] = 0;
				else
					meghdarharekat[0] = m;
				meghdarharekat[1] = m;
			}
			m = 0;
			if (jahathayemojaz[2] == 8) {
				while (satr + (m + 1) >= 5 && sotoon + m + 1 <= 5 && satr + m <= satrmohre&&sotoon + m <= sotoonmohre)
				{
					m++;
				}
				if (m == 0)
					jahathayemojaz[2] = 0;
				else
					meghdarharekat[0] = m;
				meghdarharekat[2] = m;
			}
			break;
		}//if jahat8

	}//for forjahat
}

bool vazir_easy_for_khatar(int satrmohre, int sotoonmohre, char* khodi, int jahat, int vazirsatr, int vazirsotoon, char sarnam, int meghdarharekat, char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2satr, int sarbaz2sotoon, int asbsatr, int asbsotoon, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char sarbaz1nam, char sarbaz2nam, char asbnam)
{
	//محافظت سرباز و اسب از وزیر بی معنیه
	bool ayasarbaz1mohafez = false, ayasarbaz2mohafez = false, ayaasbmohafez = false;

	if (jahat == 1)
	{

		if (vazir_move(vazirsatr, vazirsotoon, 1, meghdarharekat, map))
		{

			bool harif_nmizane = checkzarb(setplayer, vazirsatr - meghdarharekat, vazirsotoon, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);
			if (harif_nmizane == true) {
				//	bool checkzarb(char setplayer, int satr, int sotoon, char sarnam, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6])
				//	if (is_our(sarnam, khodi)) {
				//ino mizarim ta check konim bebeinim vazir mitune mohre khodio bezane ta motamen shim mitune azash mohafezat kone
				bool can_set = mohafez_darad_2(vazirsatr - meghdarharekat, vazirsotoon, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);
				if (!can_set)
					return false;
				if (map[vazirsatr - meghdarharekat][vazirsotoon] == '-') {
					map[vazirsatr - meghdarharekat][vazirsotoon] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 2)
	{
		//if (meghdarharekat == 2)
		//	cout << "salam";
		if (vazir_move(vazirsatr, vazirsotoon, 2, meghdarharekat, map))
		{
			//cout << "\njahate2\n" << meghdarharekat << vazirsatr << endl;
			//cin >> vazirsotoon;

			bool harif_nmizane = checkzarb(setplayer, vazirsatr + meghdarharekat, vazirsotoon, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);

			if (harif_nmizane == true) {
				bool can_set = mohafez_darad_2(vazirsatr + meghdarharekat, vazirsotoon, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);
				if (!can_set)
					return false;
				//if (is_our(sarnam, khodi)) {
				if (map[vazirsatr + meghdarharekat][vazirsotoon] == '-') {

					map[vazirsatr + meghdarharekat][vazirsotoon] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 3)
	{

		if (vazir_move(vazirsatr, vazirsotoon, 3, meghdarharekat, map))
		{

			bool harif_nmizane = checkzarb(setplayer, vazirsatr, vazirsotoon - meghdarharekat, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);
			if (harif_nmizane == true) {
				bool can_set = mohafez_darad_2(vazirsatr, vazirsotoon - meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);
				if (!can_set)
					return false;
				//if (is_our(sarnam, khodi)) {
				if (map[vazirsatr][vazirsotoon - meghdarharekat] == '-') {
					map[vazirsatr][vazirsotoon - meghdarharekat] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 4)
	{


		if (vazir_move(vazirsatr, vazirsotoon, 4, meghdarharekat, map))
		{

			bool harif_nmizane = checkzarb(setplayer, vazirsatr, vazirsotoon + meghdarharekat, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);
			if (harif_nmizane == true) {
				//	cout << "\njahate444444444444444444444" << meghdarharekat << vazirsatr << endl;
				//	cin >> vazirsotoon;
				bool can_set = mohafez_darad_2(vazirsatr, vazirsotoon + meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);

				if (!can_set)
					return false;
				//	bool vazir_mohafez_mimune = mohafez_darad_2(vazirsatr, vazirsotoon + meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, asbsatr, asbsotoon, map, sarnam);
				//	if (!vazir_mohafez_mimune)
				//	return false;
				//if (is_our(sarnam, khodi)) {
				if (map[vazirsatr][vazirsotoon + meghdarharekat] == '-') {
					map[vazirsatr][vazirsotoon + meghdarharekat] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 5)
	{

		if (vazir_move(vazirsatr, vazirsotoon, 5, meghdarharekat, map))
		{

			bool harif_nmizane = checkzarb(setplayer, vazirsatr - meghdarharekat, vazirsotoon + meghdarharekat, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);

			if (harif_nmizane == true) {
				bool can_set = mohafez_darad_2(vazirsatr - meghdarharekat, vazirsotoon + meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);

				if (!can_set)
					return false;
				//if (is_our(sarnam, khodi)) {
				if (map[vazirsatr - meghdarharekat][vazirsotoon + meghdarharekat] == '-') {
					map[vazirsatr - meghdarharekat][vazirsotoon + meghdarharekat] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 6)
	{

		if (vazir_move(vazirsatr, vazirsotoon, 6, meghdarharekat, map))
		{
			bool harif_nmizane = checkzarb(setplayer, vazirsatr - meghdarharekat, vazirsotoon - meghdarharekat, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);

			if (harif_nmizane == true) {
				bool can_set = mohafez_darad_2(vazirsatr - meghdarharekat, vazirsotoon - meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);

				if (!can_set)
					return false;
				//if (is_our(sarnam, khodi)) {
				if (map[vazirsatr - meghdarharekat][vazirsotoon - meghdarharekat] == '-') {
					map[vazirsatr - meghdarharekat][vazirsotoon - meghdarharekat] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 7)
	{

		if (vazir_move(vazirsatr, vazirsotoon, 7, meghdarharekat, map))
		{
			bool harif_nmizane = checkzarb(setplayer, vazirsatr + meghdarharekat, vazirsotoon - meghdarharekat, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);

			if (harif_nmizane == true) {
				bool can_set = mohafez_darad_2(vazirsatr + meghdarharekat, vazirsotoon - meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);

				if (!can_set)
					return false;
				//if (is_our(sarnam, khodi)) {
				if (map[vazirsatr + meghdarharekat][vazirsotoon - meghdarharekat] == '-') {
					map[vazirsatr + meghdarharekat][vazirsotoon - meghdarharekat] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	if (jahat == 8)
	{

		if (vazir_move(vazirsatr, vazirsotoon, 8, meghdarharekat, map))
		{

			bool harif_nmizane = checkzarb(setplayer, vazirsatr + meghdarharekat, vazirsotoon + meghdarharekat, sarnam, sarbaz1harif, sarbaz2harif, asbharif, vazirharif, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, asbharifsatr, asbharifsotoon, vazirharifsatr, vazirharifsotoon, map);

			if (harif_nmizane == true) {
				bool can_set = mohafez_darad_2(vazirsatr + meghdarharekat, vazirsotoon + meghdarharekat, setplayer, 3, vazirsatr, vazirsotoon, satrmohre, sotoonmohre, map, sarnam);

				if (!can_set)
					return false;
				//	if (is_our(sarnam, khodi)) {
				if (map[vazirsatr + meghdarharekat][vazirsotoon + meghdarharekat] == '-') {
					map[vazirsatr + meghdarharekat][vazirsotoon + meghdarharekat] = sarnam;
					map[vazirsatr][vazirsotoon] = '-';
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}

}
bool checkzarb(char setplayer, int satr, int sotoon, char sarnam, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6])
{
	//checkzarb return true bede yani azade
	//	if (satr == 1 && sotoon == 1)
	//	cout << "salammmm";
	bool cangofromsarbaz1 = true, cangofromsarbaz2 = true, cangofromasb = true, cangofromvazir = true;
	if (sarbaz1harif)
		cangofromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr, sotoon, map, sarnam);
	if (sarbaz2harif)
		cangofromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr, sotoon, map, sarnam);
	if (asbharif)
		cangofromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr, sotoon);
	if (vazirharif)
		cangofromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr, sotoon, map, sarnam);
	if (cangofromsarbaz1 == true && cangofromsarbaz2 == true && cangofromasb == true && cangofromvazir == true)
		return true;
	else
		return false;
}
bool can_zarb_for_tahdid(char setplayer, int noemohre, int sarbaz1newsatr, int sarbaz1newsotoon, char sarbaz1nam, int sarbaz2newsatr, int sarbaz2newsotoon
	, char sarbaz2nam, int asbnewsatr, int asbnewsotoon, int vazirnewsatr, int vazirnewsotoon, char vazirnammm, int sarbaz1harif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harif
	, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharif, int asbharifsatr, int asbharifsotoon, int vazirharif, int vazirharifsatr, int vazirharifsotoon)
{
	//yadet nare checkzarba bezanan false midan
	bool can_tahdid_s1h = true, can_tahdid_s2h = true, can_tahdid_asbharif = true, can_tahdid_vazirharif = true;
	//این تابع میاد چک میکنه ک مهره خودی تو محل جدیدش آیا میتونه مهره ای از حریفو بزنه(یعنی تهدیدش کنه) اگه بتونه ریتارن ترومیده
	//noemohre 1sarbaz1  2 sarbaz2  3asb  4vazir
	if (noemohre == 1)
	{
		if (sarbaz1harif)
			can_tahdid_s1h = checkzarbsarbaz(setplayer, sarbaz1newsatr, sarbaz1newsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map, sarbaz1nam);
		if (sarbaz2harif)
			can_tahdid_s2h = checkzarbsarbaz(setplayer, sarbaz1newsatr, sarbaz1newsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, map, sarbaz2nam);
		if (asbharif)
			can_tahdid_asbharif = checkzarbsarbaz(setplayer, sarbaz1newsatr, sarbaz1newsotoon, asbharifsatr, asbharifsotoon, map, sarbaz1nam);
		if (vazirharif)
			can_tahdid_vazirharif = checkzarbsarbaz(setplayer, sarbaz1newsatr, sarbaz1newsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map, sarbaz1nam);
		//yadet bashe checkzarba age betoon bezanan false midan
		if (can_tahdid_s1h == false || can_tahdid_s2h == false || can_tahdid_asbharif == false || can_tahdid_vazirharif == false)
			return true;

	}
	if (noemohre == 2)
	{
		if (sarbaz1harif)
			can_tahdid_s1h = checkzarbsarbaz(setplayer, sarbaz2newsatr, sarbaz2newsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map, sarbaz1nam);
		if (sarbaz2harif)
			can_tahdid_s2h = checkzarbsarbaz(setplayer, sarbaz2newsatr, sarbaz2newsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, map, sarbaz2nam);
		if (asbharif)
			can_tahdid_asbharif = checkzarbsarbaz(setplayer, sarbaz2newsatr, sarbaz2newsotoon, asbharifsatr, asbharifsotoon, map, sarbaz1nam);
		if (vazirharif)
			can_tahdid_vazirharif = checkzarbsarbaz(setplayer, sarbaz2newsatr, sarbaz2newsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map, sarbaz1nam);
		//yadet bashe checkzarba age betoon bezanan false midan
		if (can_tahdid_s1h == false || can_tahdid_s2h == false || can_tahdid_asbharif == false || can_tahdid_vazirharif == false)
			return true;

	}
	if (noemohre == 3)
	{
		if (sarbaz1harif)
			can_tahdid_s1h = checkzarbasb(asbnewsatr, asbnewsotoon, sarbaz1harifsatr, sarbaz1harifsatr);
		if (sarbaz2harif)
			can_tahdid_s2h = checkzarbasb(asbnewsatr, asbnewsotoon, sarbaz2harifsatr, sarbaz2harifsotoon);
		if (asbharif)
			can_tahdid_asbharif = checkzarbasb(asbnewsatr, asbnewsotoon, asbharifsatr, asbharifsotoon);
		if (vazirharif)
			can_tahdid_vazirharif = checkzarbasb(asbnewsatr, asbnewsotoon, vazirharifsatr, vazirharifsotoon);
		if (can_tahdid_s1h == false || can_tahdid_s2h == false || can_tahdid_asbharif == false || can_tahdid_vazirharif == false)
			return true;
	}
	if (noemohre == 4)
	{

		if (sarbaz1harif)
			can_tahdid_s1h = checkzarbvazir(vazirnewsatr, vazirnewsotoon, sarbaz1harifsatr, sarbaz1harifsotoon, map, vazirnammm);
		if (sarbaz2harif)
			can_tahdid_s2h = checkzarbvazir(vazirnewsatr, vazirnewsotoon, sarbaz2harifsatr, sarbaz2harifsotoon, map, vazirnammm);
		if (asbharif)
			can_tahdid_asbharif = checkzarbvazir(vazirnewsatr, vazirnewsotoon, asbharifsatr, asbharifsotoon, map, vazirnammm);
		if (vazirharif)
			can_tahdid_vazirharif = checkzarbvazir(vazirnewsatr, vazirnewsotoon, vazirharifsatr, vazirharifsotoon, map, vazirnammm);
		if (can_tahdid_s1h == false || can_tahdid_s2h == false || can_tahdid_asbharif == false || can_tahdid_vazirharif == false)
			return true;
	}
	return false;
}
bool vazir_easy(int* meghdarforkhatar, char setplayer, int *jahat, int satr, int sotoon, char sarnam, bool sarbaz1harif, bool sarbaz2harif, bool asbharif, bool vazirharif, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, char map[6][6], char* khodi, int* vazirnewsatr, int* vazirnewsotoon, int khodicount, bool khataryab)//is_our dare(be return falsash dobare deghat kon)
{
	//براي اينکه بطور صحيح با تابع وزيرايزي ايزي کارکنيم 
	//متغيري بولي بنام ايا وزيرايزي ايزي ايجاد ميکنيم 
	// وميگوئيم هرگاه اين متغيرترو بود دراتمام جهت چک شود ک اگرتو بود پايان يابد تابع
	//اومدم تمام بزرگترمساويارو بزرگتر کردم براي ام فقط
	/*	bool easygo = false;
	if (satr - 1 > 0)
	{
	//cout << is_our(map[satr - 1][sotoon], khodi);
	if (is_our(map[satr - 1][sotoon],khodi))
	{
	map[satr - 1][sotoon] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (satr + 1 < 6)
	{
	if (is_our(map[satr + 1][sotoon], khodi))
	{
	map[satr + 1][sotoon] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else	if (sotoon - 1 > 0)
	{
	if (is_our(map[satr - 1][sotoon], khodi))
	{
	map[satr][sotoon-1] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (satr - 1 > 0)
	{
	if (is_our(map[satr - 1][sotoon], khodi))
	{
	map[satr - 1][sotoon] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (sotoon+1<6)
	{
	if (is_our(map[satr][sotoon+1], khodi))
	{
	map[satr][sotoon+1] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (satr - 1 <0 && sotoon + 1>5)
	{
	if (is_our(map[satr-1][sotoon + 1], khodi))
	{
	map[satr-1][sotoon + 1] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (satr - 1 <0 && sotoon - 1 <0)
	{
	if (is_our(map[satr - 1][sotoon - 1], khodi))
	{
	map[satr - 1][sotoon - 1] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (satr + 1 >5 && sotoon - 1<0)
	{
	if (is_our(map[satr + 1][sotoon - 1], khodi))
	{
	map[satr + 1][sotoon - 1] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	else if (satr + 1 > 5 && sotoon + 1 > 5)
	{
	if (is_our(map[satr + 1][sotoon + 1], khodi))
	{
	map[satr + 1][sotoon + 1] = sarnam;
	map[satr][sotoon] = '-';
	return true;
	}
	}
	*/
	//1-bala 2-paein 3-chap 4-rast 5-bala rast 6-balachap 7-paein chap 8-paeinrast
	*meghdarforkhatar = 1;
	bool easygo = false;
	bool harekat = false;
	//okforsend = false;//miad check mikone ke aya harekat sadeamn ko
	int m = 0;
	//cout << *jahat;
	bool canescapefromsarbaz1 = true, canescapefromsarbaz2 = true, canescapefromasb = true, canescapefromvazir = true;
	for (*jahat; *jahat<9; jahat++) {
		//cout << "jahatha" << jahat << endl;//hardafe 9bar az avval check kone ama age be jahat ghabli resid continue  sho
		if (*jahat == 1)
		{
			//بيايم بگيم  يه جهت  ساده تو قسمت ايزي الو تعريف کنيم
			//بعد بعد چک کردن 4 کن گو و ايف اصلي بگيم اگه ايف نقض شد 
			//تو السش اول جهت يکي اضافه بشه بعد دوباره وزير فور ايزي اجرا ببشه
			//تا زماني ک ايف اصليمون (4تا شرطه)ترو بشه
			//براي بقيه مهرهام همينکارو بکن

			//	cout << "ok";

			if (satr - 1 < 0)
				continue;


			while (satr - m > 0 && map[satr - (m + 1)][sotoon] == '-')//[satr - (m+1) +1 hazf krdm
			{
				//مياد اول همه چيو براي خونه بالايي چک ميکنه اگه همه چي اوکي بود يکي به ام اضافه کن 

				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr - (m + 1), sotoon, map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr - (m + 1), sotoon, map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr - (m + 1), sotoon);
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr - (m + 1), sotoon, map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (satr - m > 0)
						m++;
					else
						break;
				}
			}

			if (vazir_move(satr, sotoon, 1, m, map)) {

				//	cout << "okeye";
				if (map[satr - m][sotoon] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr - m;
						*vazirnewsotoon = sotoon;
						*meghdarforkhatar = m;

						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr - m][sotoon] = sarnam;
					map[satr][sotoon] = '-';
					//cout << "m:" << m << endl;
					//cout << "sarnam" << sarnam << endl;
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 2)
		{

			if (satr + 1 > 5)
				continue;
			m = 0;
			while (satr + m < 5 && map[satr + (m + 1)][sotoon] == '-')
			{

				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr + (m + 1), sotoon, map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr + (m + 1), sotoon, map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr + (m + 1), sotoon);
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr + (m + 1), sotoon, map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (satr + m <= 5)
						m++;
					else
						break;
				}
			}
			//cout << "m:" << m;
			if (vazir_move(satr, sotoon, 2, m, map)) {

				if (map[satr + m][sotoon] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr + m;
						*vazirnewsotoon = sotoon;
						*meghdarforkhatar = m;

						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr + m][sotoon] = sarnam;
					map[satr][sotoon] = '-';
					//cout << "2";
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 3)
		{

			if (sotoon - 1 < 0)
				continue;
			m = 0;
			while (sotoon - m > 0 && map[satr][sotoon - (m + 1)] == '-')
			{

				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr, sotoon - (m + 1), map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr, sotoon - (m + 1), map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr, sotoon - (m + 1));
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr, sotoon - (m + 1), map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (sotoon - m > 0)
						m++;
					else
						break;
				}
			}
			if (vazir_move(satr, sotoon, 3, m, map)) {
				if (map[satr][sotoon - m] == '-') {
					//	cout << "kaalaa";
					//	cin >> satr;
					if (khataryab == true) {
						*vazirnewsatr = satr;
						*vazirnewsotoon = sotoon - m;
						*meghdarforkhatar = m;

						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr][sotoon - m] = sarnam;
					map[satr][sotoon] = '-';
					//	cout << "3";
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 4)
		{

			if (sotoon + 1 > 5)
				continue;
			m = 0;
			while (sotoon + m < 5 && map[satr][sotoon + (m + 1)] == '-')
			{
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr, sotoon + (m + 1), map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr, sotoon + (m + 1), map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr, sotoon + (m + 1));
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr, sotoon + (m + 1), map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (sotoon + m < 5)
						m++;
					else
						break;
				}

			}
			if (vazir_move(satr, sotoon, 4, m, map)) {
				if (map[satr][sotoon + m] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr;
						*vazirnewsotoon = sotoon + m;
						*meghdarforkhatar = m;
						return true;//hamintori gozashtam ta tabetamooom she
					}

					//cout << "iraniaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
					//cout << "m:" << m << endl;
					//cout << satr << sotoon+m;
					//cin >> m;//vazirmovejahate4 moshkel dare

					map[satr][sotoon + m] = sarnam;
					map[satr][sotoon] = '-';
					//	cout << "4";
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 5)
		{

			if (satr - 1 <= 0 && sotoon + 1 >= 5)
				continue;
			m = 0;
			while (satr - m > 0 && sotoon + m < 5 && map[satr - (m + 1)][sotoon + (m + 1)] == '-')
			{
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr - (m + 1), sotoon + (m + 1), map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr - (m + 1), sotoon + (m + 1), map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr - (m + 1), sotoon + (m + 1));
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr - (m + 1), sotoon + (m + 1), map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (satr - m >0 && sotoon + m<5)
						m++;
					else
						break;
				}
			}
			if (vazir_move(satr, sotoon, 5, m, map)) {

				if (map[satr - m][sotoon + m] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr - m;
						*vazirnewsotoon = sotoon + m;
						*meghdarforkhatar = m;
						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr - m][sotoon + m] = sarnam;
					map[satr][sotoon] = '-';
					//cout << "5";
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 6)
		{
			if (satr - 1 <= 0 && sotoon - 1 <= 0)
				continue;
			m = 0;
			while (satr - m > 0 && sotoon - m > 0 && map[satr - (m + 1)][sotoon - (m + 1)] == '-')
			{
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr - (m + 1), sotoon - (m + 1), map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr - (m + 1), sotoon - (m + 1), map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr - (m + 1), sotoon - (m + 1));
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr - (m + 1), sotoon - (m + 1), map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (satr - m > 0 && sotoon - m>0)
						m++;
					else
						break;
				}
			}
			if (vazir_move(satr, sotoon, 6, m, map)) {

				if (map[satr - m][sotoon - m] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr - m;
						*vazirnewsotoon = sotoon - m;
						*meghdarforkhatar = m;
						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr - m][sotoon - m] = sarnam;
					map[satr][sotoon] = '-';
					//cout << "6";
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 7)
		{
			if (satr + 1 >= 5 && sotoon - 1 <= 0)
				continue;
			m = 0;
			while (satr + m < 5 && sotoon - m>0 && map[satr + (m + 1)][sotoon - (m + 1)] == '-')
			{
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr + (m + 1), sotoon - (m + 1), map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr + (m + 1), sotoon - (m + 1), map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr + (m + 1), sotoon - (m + 1));
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr + (m + 1), sotoon - (m + 1), map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (satr + m < 5 && sotoon - m >0)
						m++;
					else
						break;
				}
			}
			if (vazir_move(satr, sotoon, 7, m, map)) {

				if (map[satr + m][sotoon - m] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr + m;
						*vazirnewsotoon = sotoon - m;
						*meghdarforkhatar = m;
						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr + m][sotoon - m] = sarnam;
					map[satr][sotoon] = '-';
					//cout << "7";
					break;
					return true;
				}
				else
					continue;

			}
			else
				continue;
		}
		if (*jahat == 8)
		{
			if (satr + 1 > 5 || sotoon + 1 > 5) {
				//cout << "vatannn";
				//continue;
			}

			m = 0;
			while (satr + m < 5 && sotoon + m < 5 && map[satr + (m + 1)][sotoon + (m + 1)] == '-')
			{
				if (sarbaz1harif)
					canescapefromsarbaz1 = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, satr + (m + 1), sotoon + (m + 1), map, 'v');
				if (sarbaz2harif)
					canescapefromsarbaz2 = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, satr + (m + 1), sotoon + (m + 1), map, 'v');
				if (asbharif)
					canescapefromasb = checkzarbasb(asbharifsatr, asbharifsotoon, satr + (m + 1), sotoon + (m + 1));
				if (vazirharif)
					canescapefromvazir = checkzarbvazir(vazirharifsatr, vazirharifsotoon, satr + (m + 1), sotoon + (m + 1), map, 'v');
				if (canescapefromsarbaz1 == true && canescapefromsarbaz2 == true && canescapefromasb == true && canescapefromvazir == true) {
					m++;
					break;
				}
				else {
					if (satr + m < 5 && sotoon + m<5)
						m++;
					else
						break;
				}
			}
			if (vazir_move(satr, sotoon, 8, m, map)) {
				if (map[satr + m][sotoon + m] == '-') {
					if (khataryab == true) {
						*vazirnewsatr = satr + m;
						*vazirnewsotoon = sotoon + m;
						*meghdarforkhatar = m;

						return true;//hamintori gozashtam ta tabetamooom she
					}

					map[satr + m][sotoon + m] = sarnam;
					map[satr][sotoon] = '-';
					//	cout << "8";
					break;
					return true;
				}
				else
					continue;

			}
		}
		else {
			easygo = true;
			return false;
		}
	}

	if (easygo == false)
		//	cout << "hi";
		return true;
}
bool checkzarbsarbaz(char setplayer, int satrharif, int sotoonharif, int satrmahaljadid, int sotoonmahalejadid, char map[6][6], char sarnamkhodi)
{
	//cout << satrharif << sotoonharif;
	//check mikone ke age satr sotoon mahal jadid mohre ba satrosotoon harekat zarbi sarbaz harif barabar bood oon mohre khodi tekun dade nashe(yani in tabe false bede)
	//char noekhodi = map[satrmahaljadid][sotoonharif];
	int shomarenoekhodi;//yani sarbaz nist 1 yani sarbaze
						/*if (satrharif == 3)
						{
						cout << "salam"<<setplayer;
						cout << endl << satrharif << sotoonharif << satrmahaljadid;
						cin >> satrharif;
						return true;
						}
						*/
	switch (sarnamkhodi)
	{
	case 'c':
	case 'd':
	case 's':
		shomarenoekhodi = 1;//yani sarbaz
		break;
	default:
		shomarenoekhodi = 0;//yani sarbaz nist
		break;
	}
	if (setplayer == '1') {//to age setplayer 1 bashi harifet miad bala
		if ((satrharif - 1) == satrmahaljadid && (sotoonharif - 1) == sotoonmahalejadid)
		{
			return false;
		}
		//بگيم اگه حريف سرباز بود ديگه دوتاشو اعمال نکن همينکه تو يدونه بالابري ميتوني بزنيش
		if (shomarenoekhodi != 1)
			if (satrharif - 2 == satrmahaljadid && (sotoonharif - 1 == sotoonmahalejadid || sotoonharif + 1 == sotoonmahalejadid) && map[satrharif - 1][sotoonharif] == '-'&&map[satrharif - 2][sotoonharif] == '-')
				return false;

		if ((satrharif - 1) == satrmahaljadid && (sotoonharif + 1) == sotoonmahalejadid)
		{
			return false;
		}
	}
	else
	{
		if ((satrharif + 1) == satrmahaljadid && (sotoonharif - 1) == sotoonmahalejadid)
		{
			return false;
		}
		if (shomarenoekhodi != 1)
			if (satrharif + 2 == satrmahaljadid && (sotoonharif - 1 == sotoonmahalejadid || sotoonharif + 1 == sotoonmahalejadid) && map[satrharif + 2][sotoonharif] == '-')
				return false;

		if ((satrharif + 1) == satrmahaljadid && (sotoonharif + 1) == sotoonmahalejadid)
		{
			return false;
		}
	}
	return true;

}
bool checkzarbvazir(int satrharif, int sotoonharif, int satrmahaljadid, int sotoonmahaljadid, char map[6][6], char sarnam)
{ //توجه برای همشون تو بزرگترمساوییای سطرتمپا مساویم گذاشیتم**
  //YE ESLAHATI KARDAM ROOSH
  //shoroot(!ha) dorost beshe 
  //cout << satrmahaljadid<<sotoonmahaljadid<<endl;
  //in tabe miad makan harekataye vaziro ba makan jadid mohre khodi check mikone age makan harekati
  //az vazir ba makan jadid mohre khodi barabarbood false mide
  //1-bala 2-paeiin 3-chap 4-rast 5-oribbalarast 6-oribbalachap 7-oribpaeinchap 8-oribpaeinrast
  //1
	if (satrharif < 0 && sotoonharif < 0)
		return true;
	bool edameharekat = true;

	if (satrmahaljadid < 0 || sotoonmahaljadid < 0)
		return false;
	if (satrharif == satrmahaljadid&&sotoonharif == sotoonmahaljadid)
		if (sarnam == 'c' || sarnam == 'd' || sarnam == 's')
			return false;
		else
			return true;

	int m = 0;//bala(vazir harif mikhad bala bere)
	int satrtemp = satrharif;

	while (satrtemp > satrmahaljadid)
	{
		++m;
		--satrtemp;
		if (satrtemp != satrmahaljadid&&map[satrtemp][sotoonharif] != '-'  && map[satrharif - m][sotoonharif] != map[satrmahaljadid][sotoonmahaljadid]) {
			edameharekat = false;
			break;
		}
		else
			edameharekat = true;

	}
	if (edameharekat == true && satrharif - m >= 0) {
		if ((satrharif - m) == satrmahaljadid&&sotoonharif == sotoonmahaljadid) {
			return false;//yani vazir mizanatesh pas false midim ta oon mohre khodi harekat nakone
		}
	}
	m = 0;//2paein
	satrtemp = satrharif;

	while (satrtemp < satrmahaljadid)
	{
		++m;
		++satrtemp;//dare mire samte mohre jadid pas bayad bishtar she
		if (satrtemp != satrmahaljadid&&map[satrtemp][sotoonharif] != '-' && map[satrharif + m][sotoonharif] != map[satrmahaljadid][sotoonmahaljadid]) {
			//sattemp+1 kardim chon ++ hanooz emal nashode
			//	cout << "map" << map[satrtemp][sotoonharif];
			edameharekat = false;
			break;

		}
		else
			edameharekat = true;

	}



	if (edameharekat == true && satrharif + m <= 5) {
		//cout << "edameharekat==true" << satrmahaljadid << endl;
		if ((satrharif + m) == satrmahaljadid&&sotoonharif == sotoonmahaljadid)
			return false;//yani vazir mizanatesh pas false midim ta oon mohre khodi harekat nakone
	}
	m = 0;//3chap
		  //if (satrharif == 1 && sotoonharif == 2)
		  //	cout << "vvvvvvvvv";
	int sotoontemp = sotoonharif;
	while (sotoontemp > sotoonmahaljadid)
	{
		++m;
		--sotoontemp;
		if (sotoontemp != sotoonmahaljadid&&map[satrharif][sotoontemp] != '-'  && map[satrharif][sotoonharif - m] != map[satrmahaljadid][sotoonmahaljadid]) {
			edameharekat = false;
			break;

		}
		else
			edameharekat = true;


	}
	if (edameharekat == true && sotoonharif - m >= 0) {
		if ((sotoonharif - m) == sotoonmahaljadid&&satrharif == satrmahaljadid)
			return false;//yani vazir mizanatesh pas false midim ta oon mohre khodi harekat nakone
	}
	m = 0;//4rast

	sotoontemp = sotoonharif;
	while (sotoontemp < sotoonmahaljadid)
	{
		++m;
		++sotoontemp;
		if (sotoontemp != sotoonmahaljadid&&map[satrharif][sotoontemp] != '-' && map[satrharif][sotoonharif + m] != map[satrmahaljadid][sotoonmahaljadid]) {
			edameharekat = false;
			break;

		}
		else
			edameharekat = true;

	}

	if (edameharekat == true && sotoonharif + m <= 5)
	{

		if ((sotoonharif + m) == sotoonmahaljadid&&satrharif == satrmahaljadid) {
			//cout << "M:" << m << sotoontemp << endl;
			//	cin >> m;
			return false;
		}
	}
	m = 0;//oribbalarast
	satrtemp = satrharif;//baraye inke khodesho shamel nashe(jhaye khode mohre khodi)-1 
	sotoontemp = sotoonharif;
	while (satrtemp >satrmahaljadid)
	{
		++m;
		--satrtemp;//گفتيم سطرتمپ شروع ميکنه از وزير حريف ميره سمت مهره خودي
		if (satrharif != satrmahaljadid&&sotoonharif != sotoonmahaljadid&&map[satrharif - m][sotoonharif + m] != '-' && (map[satrharif - m][sotoonharif + m] != '-') && map[satrharif - m][sotoonharif + m] != map[satrmahaljadid][sotoonmahaljadid]) {//حواست باشه که براي اوريب چطور خونه ها خالي باشند
			edameharekat = false;
			break;
		}
		else
			edameharekat = true;

	}
	if (edameharekat == true && satrharif - m >= 0 && sotoonharif + m <= 5)
	{

		if ((satrharif - m) == satrmahaljadid && (sotoonharif + m) == sotoonmahaljadid)//دليلش اينه ک با سطر وستون محل جديد جور شه مثبتا مثبت 1 منفيا منفي 1
			return false;
	}
	m = 0;//oribbalachap
	satrtemp = satrharif;
	sotoontemp = sotoonharif;
	while (satrtemp > satrmahaljadid)//پائين نقشه 4 5 بالا کمتره ها(حريف ميخواد بره بالا چپ
	{
		++m;
		--satrtemp;
		if (satrharif != satrmahaljadid&&sotoonharif != sotoonmahaljadid && (map[satrharif - m][sotoonharif - m] != '-') && map[satrharif - m][sotoonharif - m] != map[satrmahaljadid][sotoonmahaljadid]) {
			edameharekat = false;
			break;
		}
		else
			edameharekat = true;

	}
	if (edameharekat == true && satrharif - m >= 0 && sotoonharif - m >= 0)
	{
		if ((satrharif - m) == satrmahaljadid && (sotoonharif - m) == sotoonmahaljadid)
			return false;
	}
	m = 0;//oribpaeinchap
	satrtemp = satrharif;
	sotoontemp = sotoonharif;
	while (satrtemp < satrmahaljadid)
	{
		++m;
		++satrtemp;
		if (satrharif != satrmahaljadid&&sotoonharif != sotoonmahaljadid&&map[satrharif + m][sotoonharif - m] != '-' && (map[satrharif + m][sotoonharif - m] != '-') && map[satrharif + m][sotoonharif - m] != map[satrmahaljadid][sotoonmahaljadid]) {
			edameharekat = false;
			break;//مشکل از اينه
		}
		else
			edameharekat = true;


	}
	if (edameharekat == true && satrharif + m <= 5 && sotoonharif - m >= 0)
	{
		if ((satrharif + m) == satrmahaljadid && (sotoonharif - m) == sotoonmahaljadid)
			return false;
	}
	m = 0;//oribpaeinrast
	satrtemp = satrharif;
	sotoontemp = sotoonharif;
	while (satrtemp < satrmahaljadid)
	{
		++m;
		++satrtemp;
		if (satrharif != satrmahaljadid&&sotoonharif != sotoonmahaljadid&&map[satrharif + m][sotoonharif + m] != '-' && (map[satrharif + m][sotoonharif + m] != '-') && map[satrharif + m][sotoonharif + m] != map[satrmahaljadid][sotoonmahaljadid]) {
			edameharekat = false;
			break;
		}
		else
			edameharekat = true;

	}
	if (edameharekat == true && satrharif + m <= 5 && sotoonharif + m <= 5)
	{
		if ((satrharif + m) == satrmahaljadid && (sotoonharif + m) == sotoonmahaljadid)
		{
			//cout<<satrmahaljadid << sotoonmahaljadid;
			//cout << "Salammmmm";
			////cin >> satrharif;
			return false;
		}
	}
	return true;
}
bool checkzarbasb(int satrharif, int sotoonharif, int satrmahaljadid, int sotoonmahaljadid)
{
	//age mahal jadid barabare harekat zarbi asb shod return false mide
	if (satrharif - 2 == satrmahaljadid && (sotoonharif - 1 == sotoonmahaljadid || sotoonharif + 1 == sotoonmahaljadid))
	{
		return false;
	}
	if (satrharif + 2 == satrmahaljadid && (sotoonharif - 1 == sotoonmahaljadid || sotoonharif + 1 == sotoonmahaljadid))
	{
		return false;
	}
	if (satrharif - 1 == satrmahaljadid && (sotoonharif - 2 == sotoonmahaljadid || sotoonharif + 2 == sotoonmahaljadid))
	{
		return false;
	}
	if (satrharif + 1 == satrmahaljadid && (sotoonharif - 2 == sotoonmahaljadid || sotoonharif + 2 == sotoonmahaljadid))
	{
		return false;
	}
	return true;
}
bool zarbsarbaz(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char*khodi, int*satrsarbazjadid, int* sotoonsarbazjadid, bool khataryab)//is_our dare
{

	if (sarbaz_move(satr, sotoon, map))
	{
		//	cout << costnn << satr << sotoon;
		//cout << "mantaghe:" << satr << sotoon << endl;
		//cout << "\n costnn:" << costnn << endl;;
		if (map[satr - 1][sotoon + 1] == costnn)
		{
			if (khataryab == true)
			{
				*satrsarbazjadid = satr - 1;
				*sotoonsarbazjadid = sotoon + 1;
				return true;
			}
			map[satr - 1][sotoon + 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}

		else if (map[satr - 1][sotoon - 1] == costnn)
		{
			if (khataryab == true)
			{
				*satrsarbazjadid = satr - 1;
				*sotoonsarbazjadid = sotoon - 1;
				return true;
			}
			map[satr - 1][sotoon - 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
	}

	return false;

}
bool zarbsarbaz2(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char*khodi, int* satrsarbazjadid, int* sotoonsarbazjadid, bool khataryab = false)//is_our dare
{

	if (sarbaz_2_move(satr, sotoon, map))
	{
		//	cout << costnn << satr << sotoon;
		//cout << "mantaghe:" << satr << sotoon << endl;
		//cout << "\n costnn:" << costnn << endl;;
		if (map[satr + 1][sotoon + 1] == costnn)
		{
			if (khataryab == true)
			{
				*satrsarbazjadid = satr + 1;
				*sotoonsarbazjadid = sotoon + 1;
				return true;
			}
			//cout << "mantaghe";
			map[satr + 1][sotoon + 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}

		else if (map[satr + 1][sotoon - 1] == costnn)
		{
			if (khataryab == true)
			{
				*satrsarbazjadid = satr + 1;
				*sotoonsarbazjadid = sotoon - 1;
				return true;
			}
			map[satr + 1][sotoon - 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
	}

	return false;

}
bool asb_move(int satr, int sotoon, int jahat)
{
	if (jahat == 1)//balachap
	{
		if (satr - 2 < 0 || sotoon - 1 < 0)
			return false;
		return true;
	}
	else if (jahat == 2)//balarast
	{
		if (satr - 2 < 0 || sotoon + 1 > 5)
			return false;
		return true;
	}
	else if (jahat == 3)//paeinchap
	{
		if (satr + 2 > 5 || sotoon - 1 < 0)
			return false;
		return true;
	}
	else if (jahat == 4)//paeinrast
	{
		if (satr + 2 > 5 || sotoon + 1 > 5)
			return false;
		return true;
	}
	else if (jahat == 5)
	{
		if (satr - 1 < 0 || sotoon + 2 > 5)
			return false;
		return true;
	}
	else if (jahat == 6)
	{
		if (satr - 1 < 0 || sotoon - 2 < 0)
			return false;
		return true;
	}
	else if (jahat == 7)
	{
		if (satr + 1 > 5 || sotoon - 2 < 0)
			return false;
		return true;
	}
	else if (jahat == 8)
	{
		if (satr + 1 > 5 || sotoon + 2 > 5)
			return false;
		return true;
	}


}
bool zarbasb(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char* khodi, int* satrasbjadid, int* sotoonasbjadid, bool khataryab)//is_our dare
{

	//1=balachap 2-balarast 3-paein chap 4-paein rast 5-balarast 6-bala chap 7-paein chap 8-paein rast
	//ba for radifesh kon
	//cout <<endl<< satr << sotoon;
	//	if(is_our(map[satr][sotoon],khodi))
	//for (int jahat = 1; jahat < 9; jahat++) {
	//cout << "\n jahat:" << jahat << endl;
	//if (satr - 1 < 0 || sotoon - 1 < 0 || satr + 1 > 6 || sotoon + 1 > 6)
	//	return false;bara harkodoom shart jodagane bezar
	if (sarnam == NULL)
		return false;
	if (map[satr - 2][sotoon - 1] == costnn)
	{

		if (satr - 2 < 0 || sotoon - 1 < 0)
			return false;
		if (is_our(map[satr - 2][sotoon - 1], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr - 2;
				*sotoonasbjadid = sotoon - 1;
				return true;
			}
			map[satr - 2][sotoon - 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;

		}
		else
			return false;
	}



	else if (map[satr - 2][sotoon + 1] == costnn)
	{
		//	cout << costnn;

		if (satr - 2 <0 || sotoon + 1  > 5)
			return false;
		if (is_our(map[satr - 2][sotoon + 1], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr - 2;
				*sotoonasbjadid = sotoon + 1;
				return true;
			}
			map[satr - 2][sotoon + 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		else
			return false;
	}



	else if (map[satr + 2][sotoon - 1] == costnn)
	{
		if (satr + 2 > 5 || sotoon - 1 < 0)
			return false;
		if (is_our(map[satr + 2][sotoon - 1], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr + 2;
				*sotoonasbjadid = sotoon - 1;
				return true;
			}
			map[satr + 2][sotoon - 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		else
			return false;


	}

	else if (map[satr + 2][sotoon + 1] == costnn)
	{
		if (satr + 2 > 5 || sotoon + 1 > 5)
			return false;
		if (is_our(map[satr + 2][sotoon + 1], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr + 2;
				*sotoonasbjadid = sotoon + 1;
				return true;
			}
			map[satr + 2][sotoon + 1] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		else
			return false;


	}

	else if (map[satr - 1][sotoon + 2] == costnn)
	{
		if (satr - 1 <0 || sotoon + 2 > 5)
			return false;
		if (is_our(map[satr - 1][sotoon + 2], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr - 1;
				*sotoonasbjadid = sotoon + 2;
				return true;
			}
			map[satr - 1][sotoon + 2] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		return false;



	}

	else if (map[satr - 1][sotoon - 2] == costnn)
	{
		if (satr - 1 < 0 || sotoon - 2 < 0)
			return false;
		if (is_our(map[satr - 1][sotoon - 2], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr - 1;
				*sotoonasbjadid = sotoon - 2;
				return true;
			}
			map[satr - 1][sotoon - 2] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		else
			return false;

	}

	else if (map[satr + 1][sotoon + 2] == costnn)
	{

		if (satr + 1 > 5 || sotoon + 2 >5)
			return false;

		if (is_our(map[satr + 1][sotoon + 2], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr + 1;
				*sotoonasbjadid = sotoon + 2;
				return true;
			}
			map[satr + 1][sotoon + 2] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		return false;


	}

	else if (map[satr + 1][sotoon - 2] == costnn)
	{
		if (satr + 1 > 5 || sotoon - 2 < 0)
			return false;
		if (is_our(map[satr + 1][sotoon - 2], khodi)) {
			if (khataryab == true)
			{
				*satrasbjadid = satr + 1;
				*sotoonasbjadid = sotoon - 2;
				return true;
			}
			map[satr + 1][sotoon - 2] = sarnam;
			map[satr][sotoon] = '-';
			return true;
		}
		return false;




	}
	else

		return false;

	//return false;//age ta for hichi javab nadad pas asb nis dg
}
void search_mohre_darkhatar(char setplayer, int sarbaz1mojood, int sarbaz2mojood, int asbmojood, int vazirmojood, int sarbaz1harif, int sarbaz2harif, int asbharif, int vazirharif, int asbsatr, int asbsotoon, int sarbaz1harifsatr, int sarbaz1harifsotoon, int sarbaz2harifsatr, int sarbaz2harifsotoon, int asbharifsatr, int asbharifsotoon, int vazirharifsatr, int vazirharifsotoon, int sarbaz1satr, int sarbaz1sotoon, int sarbaz2sotoon, int sarbaz1nam, int sarbaz2satr, int sarbaz2nam, int vazirsatr, int vazirsotoon, int asbnam, char vazirnammm, bool* sarbaz1darkhatar, bool* sarbaz2darkhatar, bool* asbdarkhatar, bool* vazirdarkhatar)
{
	bool farar_az_sarbaz1harif = true, farar_az_sarbaz2harif = true;//to khode ifa tarifeshun kon na inja
	bool farar_az_asbharif = true, farar_az_vazirharif = true;
	if (sarbaz1mojood)
	{
		if (sarbaz1harif)
			farar_az_sarbaz1harif = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz1satr, sarbaz1sotoon, map, sarbaz1nam);
		if (sarbaz2harif)
			farar_az_sarbaz2harif = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz1satr, sarbaz1sotoon, map, sarbaz1nam);
		if (asbharif)
			farar_az_asbharif = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz1satr, sarbaz1sotoon);
		if (vazirharif)
			farar_az_vazirharif = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz1satr, sarbaz1sotoon, map, sarbaz1nam);
		if (farar_az_sarbaz1harif == false || farar_az_sarbaz2harif == false || farar_az_asbharif == false || farar_az_vazirharif == false)
		{
			*sarbaz1darkhatar = true;
		}
	}
	if (sarbaz2mojood)
	{

		if (sarbaz1harif)
			farar_az_sarbaz1harif = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, sarbaz2satr, sarbaz2sotoon, map, sarbaz2nam);
		if (sarbaz2harif)
			farar_az_sarbaz2harif = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, sarbaz2satr, sarbaz2sotoon, map, sarbaz2nam);
		if (asbharif)
			farar_az_asbharif = checkzarbasb(asbharifsatr, asbharifsotoon, sarbaz2satr, sarbaz2sotoon);
		if (vazirharif)
			farar_az_vazirharif = checkzarbvazir(vazirharifsatr, vazirharifsotoon, sarbaz2satr, sarbaz2sotoon, map, sarbaz2nam);
		if (farar_az_sarbaz1harif == false || farar_az_sarbaz2harif == false || farar_az_asbharif == false || farar_az_vazirharif == false)
		{
			*sarbaz2darkhatar = true;
		}
	}
	if (asbmojood)
	{
		if (sarbaz1harif)
			farar_az_sarbaz1harif = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, asbsatr, asbsotoon, map, asbnam);
		if (sarbaz2harif)
			farar_az_sarbaz2harif = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, asbsatr, asbsotoon, map, asbnam);
		if (asbharif)
			farar_az_asbharif = checkzarbasb(asbharifsatr, asbharifsotoon, asbsatr, asbsotoon);
		if (vazirharif)
			farar_az_vazirharif = checkzarbvazir(vazirharifsatr, vazirharifsotoon, asbsatr, asbsotoon, map, asbnam);
		if (farar_az_sarbaz1harif == false || farar_az_sarbaz2harif == false || farar_az_asbharif == false || farar_az_vazirharif == false)
		{
			*asbdarkhatar = true;
		}
	}
	if (vazirmojood)
	{
		if (sarbaz1harif)
			farar_az_sarbaz1harif = checkzarbsarbaz(setplayer, sarbaz1harifsatr, sarbaz1harifsotoon, vazirsatr, vazirsotoon, map, vazirnammm);
		if (sarbaz2harif)
			farar_az_sarbaz2harif = checkzarbsarbaz(setplayer, sarbaz2harifsatr, sarbaz2harifsotoon, vazirsatr, vazirsotoon, map, vazirnammm);
		if (asbharif)
			farar_az_asbharif = checkzarbasb(asbharifsatr, asbharifsotoon, vazirsatr, vazirsotoon);
		if (vazirharif)
			farar_az_vazirharif = checkzarbvazir(vazirharifsatr, vazirharifsotoon, vazirsatr, vazirsotoon, map, vazirnammm);
		if (farar_az_sarbaz1harif == false || farar_az_sarbaz2harif == false || farar_az_asbharif == false || farar_az_vazirharif == false)
		{
			*vazirdarkhatar = true;
		}
	}
}
bool vazir_move(int satr, int sotoon, int jahat, int i, char map[6][6])
{
	if (jahat == 1)
	{
		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{

			if (map[satr - m][sotoon] != '-') {

				return false;
			}
			m++;
		}
		return true;
	}
	if (jahat == 2)
	{

		//cout << satr<<"salamirani";
		//cin >> sotoon;
		//cout << i;

		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr + m][sotoon] != '-')
				return false;

			m++;
		}
		return true;
	}
	if (jahat == 3)
	{
		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr][sotoon - m] != '-')
				return false;

			m++;
		}
		return true;
	}
	if (jahat == 4)
	{

		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr][sotoon + m] != '-')
				return false;
			m++;
		}
		return true;

	}
	if (jahat == 5)
	{

		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr - m][sotoon + m] != '-')
				return false;

			m++;
		}
		return true;
	}
	if (jahat == 6)
	{
		//cout << "jahat1";
		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr - m][sotoon - m] != '-')
				return false;

			m++;
		}
		return true;
	}
	if (jahat == 7)
	{

		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr + m][sotoon - m] != '-')
				return false;

			m++;
		}
		return true;
	}
	if (jahat == 8)
	{
		if (i == 1)
			return true;
		int m = 1;
		while (m < i)
		{
			if (map[satr + m][sotoon + m] != '-')
				return false;

			m++;
		}

	}
	return true;
}
bool zarbvazir(int satr, int sotoon, char sarnam, char costnn, char map[6][6], char* khodi, int* satrjadid, int* sotoonjadid, bool khataryab)//is_our dare
{
	//1-bala 2-paein 3-chap 4-rast 5-balarast 6-balachap 7-paeinchap 8-paeinrast
	int i = 1;
	//if(vazir_move(satr,sotoon,1,1))
	//cout<<'iran'
	bool allowvazir = false;

	while (satr - i >= 0)
	{

		if (map[satr - i][sotoon] == costnn)
		{
			//cout << "hel";
			if (vazir_move(satr, sotoon, 1, i, map))
			{
				if (is_our(map[satr - i][sotoon], khodi)) {
					if (khataryab == true) {
						*satrjadid = satr - i;
						*sotoonjadid = sotoon;
						return true;
					}
					map[satr - i][sotoon] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
	}
	i = 1;
	while (satr + i < 6)
	{
		if (map[satr + i][sotoon] == costnn)
		{

			if (vazir_move(satr, sotoon, 2, i, map))
			{
				//if (satr == 1 && sotoon == 3) {
				//cout << satr;
				//cin >> sotoon;
				//}
				if (is_our(map[satr + i][sotoon], khodi)) {
					if (khataryab == true) {
						*satrjadid = satr + i;
						*sotoonjadid = sotoon;
						return true;
					}
					map[satr + i][sotoon] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
	}
	i = 1;

	while (sotoon - i >= 0)
	{
		if (map[satr][sotoon - i] == costnn)
		{

			if (vazir_move(satr, sotoon, 3, i, map))
			{
				if (is_our(map[satr][sotoon - i], khodi)) {

					if (khataryab == true) {
						*satrjadid = satr;
						*sotoonjadid = sotoon - i;
						return true;
					}
					map[satr][sotoon - i] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;

	}
	i = 1;
	while (sotoon + i < 6)
	{

		if (map[satr][sotoon + i] == costnn)
		{
			if (vazir_move(satr, sotoon, 4, i, map))
			{
				if (is_our(map[satr][sotoon + i], khodi)) {
					//cout << "noooooooooooooooooooooooooooooooo";
					if (khataryab == true) {
						*satrjadid = satr;
						*sotoonjadid = sotoon + i;
						return true;
					}
					map[satr][sotoon + i] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
	}
	i = 1;
	while (satr - i >= 0 && sotoon + i<6)
	{
		if (map[satr - i][sotoon + i] == costnn)
		{

			if (vazir_move(satr, sotoon, 5, i, map))
			{
				if (is_our(map[satr - i][sotoon + i], khodi)) {
					if (khataryab == true) {
						*satrjadid = satr - i;
						*sotoonjadid = sotoon + i;
						return true;
					}
					map[satr - i][sotoon + i] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
	}
	i = 1;
	while (satr - i >= 0 && sotoon - i >= 0)
	{
		if (map[satr - i][sotoon - i] == costnn)
		{

			if (vazir_move(satr, sotoon, 6, i, map))
			{

				if (is_our(map[satr - i][sotoon - i], khodi)) {
					if (khataryab == true) {
						*satrjadid = satr - i;
						*sotoonjadid = sotoon - i;
						return true;
					}
					map[satr - i][sotoon - i] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
	}
	i = 1;
	while (satr + i < 6 && sotoon - i >= 0)
	{
		if (map[satr + i][sotoon - i] == costnn)
		{

			if (vazir_move(satr, sotoon, 7, i, map))
			{
				if (is_our(map[satr + i][sotoon - i], khodi)) {
					if (khataryab == true) {
						*satrjadid = satr + i;
						*sotoonjadid = sotoon - i;
						return true;
					}
					map[satr + i][sotoon - i] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
	}
	i = 1;
	while (satr + i < 6 && sotoon + i<6)
	{
		if (map[satr + i][sotoon + i] == costnn)
		{

			if (vazir_move(satr, sotoon, 8, i, map))
			{
				if (is_our(map[satr + i][sotoon + i], khodi)) {
					if (khataryab == true) {
						*satrjadid = satr + i;
						*sotoonjadid = sotoon + i;
						return true;
					}
					map[satr + i][sotoon + i] = sarnam;
					map[satr][sotoon] = '-';
					allowvazir = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		i++;
		//vazir akharin zarbas age vazir natune bezane pas ye eshkali hast
	}
	if (allowvazir == false)
		return false;
}
int writefile(char setplayer, char map[6][6], char* fname)
{
	char ch = 'k';

	ofstream in(fname, ios::out);
	if (!in)
		cout << "Error For Writing ";

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			/*	if (setplayer == '1') {
			switch (map[i][j])
			{
			case 'a':
			map2[i][j] = 'b';
			break;
			case 'e':
			map2[i][j] = 'f';
			break;
			case 'c':
			map2[i][j] = 'd';
			break;
			case 'b':
			map2[i][j] = 'a';
			break;
			case 'f':
			map2[i][j] = 'e';
			break;
			case 'd':
			map2[i][j] = 'c';
			break;
			case '-':
			map2[i][j] = '-';

			}

			map[i][j] = map2[5 - i][j];
			*/
			ch = map[i][j];
			in << ch;
		}

		in << "\n";
	}

	in.close();
	return 0;
}
