
#include<iostream>
using namespace std;

struct MyStruct
{
public:
	int a;
	int b;
};

class MyClass
{
private:
	char name; 
	int age; 
	string hobby;

public:
	int a;
	int b;
	MyClass(char _name, int _age, string _hobby);
	void ShowInfo(); 
	void Study(); 
	void Sleep();
};

MyClass::MyClass(char _name, int _age, string _hobby) {
	name = _name;
	age = _age;
	hobby = _hobby;
}

void MyClass::ShowInfo() {
	cout << "이름: " << name << ", 나이: " << age << ", 취미: " << hobby << endl;
}

void MyClass::Study() {
	cout << "공부합시다." << hobby << endl;
}

void MyClass::Sleep() {
	cout << "잠을 자죠" << hobby << endl;
}



int main() {

	//cout << "HelloWorld" << endl;
	//
	//string input = "";
	//
	//cin >> input;
	//cout << "Your input word is " << input << endl;

	////cout = 출력	(console out)
	////cin = 입력	(console in)
	////endl = 엔터	(end line)
	//cout << "지옥으로 온걸 환영한다. ㅋㅋㅋㅋㅋ" << endl;
	//cout << 'a' << endl;
	//cout << "지금이라도 늦지 않았어....";
	//cout << 1234 << endl;
	//cout << "★★★★★★★★★★★★" << endl;
	//cout << "★★                ★★" << endl;
	//cout << "★★    사랑해요    ★★" << endl;
	//cout << "★★                ★★" << endl;
	//cout << "★★★★★★★★★★★★" << endl;


	//숙제1 : 개인블로그 만들기, cout 캐릭터 그려오기.
	//카테고리 나누기 (c# c++ 유니티 등등)
	//깃허브주소, 영상링크, 블로그링크

	cout << "                  :/+ossyyhhhhhhhhhhhhhhhhysooooooo+//:..`                                          " << endl;
	cout << "        `dNNy+/`--:/+oooyMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNho+/:.`           ...              " << endl;
	cout << "       :hhoNN+`//:..```.MMMMMMMMMMMMMMMMMMMNMMMMMMMMMMMMMMMMMMMd``..:/ooooo++/ oyyNNN+              " << endl;
	cout << "        :hhoNN/``/+ooo+o+++/::...``````````.-://-+so/://+ohsyhdmmsooo+/:-.````` hMsod/m`            " << endl;
	cout << "        `oNMMMNh:-.``             `.-.-/+++/-.:ymNMNNmy/..`  ```./o+/..-/+ooo+/ hM/sm:s`            " << endl;
	cout << "          :mMMMMNo`            -+hms/:-.`   `:+oMMhssyhs`          .:::o+//:-`` `/y:MMM/            " << endl;
	cout << "           -dMMMMMd:        ./ohNh-           :mMs`                 :dd-```.-/+:` d`NMMd            " << endl;
	cout << "            `yMMMMMNd.   `/+//dMy`           :NMo`                `oNm.       `-++o-yMMM:           " << endl;
	cout << "             `oNMMMMs: .+o-`/NMs`   `.-::///smMh::-.`            `yMN-           `oNmMMmh           " << endl;
	cout << "               /NMMMy/+o-  +NMs`-/shmmmmddddhddddmmmmho/-`      `hMN/             /hoMd.N.          " << endl;
	cout << "                +NMMNs-   /NMN/dNmds+:-.```` .y``.-:+sdmNds:.   yMMy              .--Ns sy.         " << endl;
	cout << "                 +Md:    .NMMm/s:.`          y:       `.:sdNms-/MMN-              -dNMs  /h/        " << endl;
	cout << "               .oms`   `//MNy:`             /s            `:smhyMMh                .ymh`  .ho       " << endl;
	cout << "              .dm:`   :dN/o.               .h`               .:sMMs                  .`    `ho`     " << endl;
	cout << "              sm-   `yNNs`          ``.... o/..`               .sN+y.                       sMy.    " << endl;
	cout << "             +m-   -dMd-        `-/o+/:---`.`-://:.`             -:Mm:                     :MMMm-   " << endl;
	cout << "            /N/   :mMh`       -+oyo/::- `..````  `://.            `yMN:                    mMMMMd   " << endl;
	cout << "           -Ny   :NMy`      -yNMMMMMNdsymNmmdhhyoo/:/+-`           `sMN/                  :MMMMMN`  " << endl;
	cout << "           hN.  .mMy      `sNMMMMMNdydMMMMsMmoMyhMhNMNmm+            yMN.                 dMMMMMM`  " << endl;
	cout << "          :Ms   yMd`     .dMMMMMMmymMMMmyMshm/N:NshNhhMMMs`          `mMd                .MMMMMMM`  " << endl;
	cout << "          hM.  -MM/     `dMMMMMMmyMMMmsNh+sshhhhy+yodmhhMMy           /MM/               /MMMMMMM`  " << endl;
	cout << "         `Nd   yMd      oMMMMMMNsMMMhmmoohMMMMMMMMms+ymNdmM+           dMd               yMMMMMMM`  " << endl;
	cout << "         -Ms  `NMs      mMMMMMMhmMMMNhs/NMMMMMMMMMMMosyhmMMN`          oMM`             .NMMMMMMM`  " << endl;
	cout << "         -M+  -MM/     .MMMMMMM+MMMdhh+hMMMMMMMMMMMMm+yyhhMM/          :MM:             oMMMMMMMm   " << endl;
	cout << "         /M:  -MM:     :MMMMMMMsMMMhhy+dMMMMMMMMMMMMm/yyhhMM+          -MM/             yMMMMMMMm   " << endl;
	cout << "         +M+  -MM/     /MMMMMMMymMMMNysoMMMMMMMMMMMM+ohNMNMM+          :MM:             mMMMMMMMy   " << endl;
	cout << "         .My  .MM+     -MMMMMMMNyMMNdNd+omMMMMMMMMmo+mmyyNMM:          /MM-            `NMMMMMMMo   " << endl;
	cout << "          my   mMh      mMMMMMMMdyMMMhhNoo+yyhhhssosNyymMhNm           yMN`            .MMMMMMMM:   " << endl;
	cout << "          om   oMN.     omMMMMMMMdhNMMMymN/N+dyym+NdsmMNyhM:          `NMs             /MMMMMMMM.   " << endl;
	cout << "          `m:  `NMy      /y:/oydmNNydNMMMdmMoMN+MmhMNNhymM+           sMN.             /MMMMMMMm    " << endl;
	cout << "           :d`  +MM+     `sd:  ```-:..+hdmNNNMMmMMdyyymMN/           /MMo              oMMMMMMMs    " << endl;
	cout << "            yo   yMN:      /hh-         ```..-::/.`:osys-           -NMh`              oMMMMMMM/    " << endl;
	cout << "            .m-  `hMN:      `+hs:`                 `-+.            :mMh`               oMMMMMMN`    " << endl;
	cout << "             /d`  `yMN-       `-sys/-           .-:/.`            /NMy`                oMMMMMMy     " << endl;
	cout << "             `hh`  `+m:h-        `./+`h--++/://:-.`             .yMNo`                 oMMMMMM:     " << endl;
	cout << "            -dMMh`   .sMN:`           N-``.```                 +mMd:                   /MMMMMd`     " << endl;
	cout << "          -sNMMMds-   oMM/ys-         d:                    -o+dd+`                    -MMMMN:      " << endl;
	cout << "        .sNMMMMN/.:+` `mM/hNNh+.`     y/                 .//NMs-`                      `MMNy-       " << endl;
	cout << "      .sNMMMMMNms  ./-`:Nd.-odNNds/.` o+            .-:ohNNoMMs                        .o/-         " << endl;
	cout << "    `omMMMMMNy:.     -/:+Nh` `-+hmNNmhdd+/::::://oyhmNNmdo:/MMy               `.+o-  `+y-           " << endl;
	cout << "  `/dMMMMNdo-          ./hMy.    `-:+shdNMNmmmmmmdhyo:-`   /MMh               +mMd../y/`            " << endl;
	cout << "  /MMohmds:o/:.`         `omm/.`        sMm-....`          `NMN.           ...-+M+`d+`              " << endl;
	cout << "  +MMsys-``.-/+os+/:-.``   .//://.`     `dMy                :NMs        `./yydyhM-+y                " << endl;
	cout << "  :ydh+++-:os+-..-dMMNdhs+/-.```.://.`  /sMMs---.            -dN-   `.:+/:. -ymMMsm:                " << endl;
	cout << "            `-/ossmMMMMMMMMMNmmhyso+ooo/-:osyyo/.           ``.oh:/+/:.    .s.NMMN-                 " << endl;
	cout << "                 `/shmNNMMMMMMMMMMMMMMMMMmddhyyss++/////osoooooo+/:--.``  `h-hMMN/                  " << endl;
	cout << "                      .-/+shdmNNNMMMMMMMMMMMMMMMMMMMMMMMMh:::::::::::++o:yh+oNNMo                   " << endl;
	cout << "                              `.-:/osyhddNNNNMMMMMMMMMMMMo-----------.``-Md s/:o`                   " << endl;
	cout << "                                          ``.:://++oooyyo+::-------:/+o+:Nmomsd/                    " << endl;
	cout << "                                                                         `.ydh.                     " << endl;

	cout << "    ================================================================================== " << endl;
	                                                  
cout << "               .,--,.                             " << endl;
cout << "             :*;;:;;;*;.         .-:;:,           " << endl;
cout << "           :!::::::::::;*     .!!;;::::;!         " << endl;
cout << "         .*;:::::::::::::;; ,!;::::::::::!        " << endl;
cout << "        .!:::::::::::::::::=;:::::::::::::*       " << endl;
cout << "        !::::::::::::::::::;!::::::::::::::!      " << endl;
cout << "       *;:::::::::!!*!;:::::!;:::::::::::::;.     " << endl;
cout << "      !:::::::;*!;:::;;;**;::!:::::::::::::::     " << endl;
cout << "     ,;:::::;*;:::;;;;;::;!*;*:;;!!!***!!;;:!     " << endl;
cout << "     !::::::!::;*~.    ~!!;:*$*;;::::::::;;*=!,   " << endl;
cout << "    ~;::::::::;:           ~=;!:::;::=!~~*$$=::*- " << endl;
cout << "    !::::::::*.     $@@@$:   !*=;::*-         ,!*!" << endl;
cout << "   .;:::::::*      -@@!@@@*   -=*;*        ,..   !" << endl;
cout << "   *:::::::*       =@@@@!@@!    **:       $@@@:   " << endl;
cout << " ;**::::;!:        $@@@@=@@$    .;,      $@*@@@*  " << endl;
cout << "!;;;::::-          !@@:@@@@$     :       @@@@!#@- " << endl;
cout << "::;:::::!!         ,@@@@@@@!      !      @@$@@@@; " << endl;
cout << "::!:::::::!         ,#@@@@=       :      ;@#@@@@; " << endl;
cout << "::*:::::::=,           ~~.        ~       #@@@@@  " << endl;
cout << "::;:::::::;=-                     -        .!*=.  " << endl;
cout << ":::::::::::;*:                    ;               " << endl;
cout << "::::::::::::;**~                  :               " << endl;
cout << "::::::::::::;:!*!$-              =.               " << endl;
cout << "::::::::::::::::;=;;=~         ~=;!             ,=" << endl;
cout << "::::::::::::::::::;*!;;!!***!!;;::;~           !*," << endl;
cout << ":::::::::::::::::::::;!*!!!!:::::::;;*;~~~~~!*=!  " << endl;
cout << ":::::::::;;:::::::::::::::::::::::::**;;;;;;*$.   " << endl;
cout << "::::::::#::#:::::::::::::::::::::::::;;$;;;;::!.  " << endl;
cout << ":::::::#~~~~$::::::::::::::::::::::::::;;::::::!. " << endl;
cout << ":::::::=~~~~:$::::::::::::::::::::::::::::::::::! " << endl;
cout << "::::::;;~~~~~:#;:;::::::::::::::::::::::::::::::;~" << endl;
cout << ":::::::*~~:=~~~=*::::::::::::::::::::::::::::::::*" << endl;
cout << ":::::::$:~~;=~~~:$*::::::::::::::::::::::::::::::;" << endl;
cout << ":::*!:::#:~~~$~~~~:=$!:::::::::::::::::::::::::::;" << endl;
cout << ";:;;=::;;#~~~~#:~~~~~:$*:::::;::::::::::::::::::;*" << endl;
cout << "!:=:=:$;=;@~:~~!$~~~~~~~*$*!;::::::::::::::::;*=::" << endl;
cout << "=*;:=:*:=:;#:~~~:;;$!~~~~~~:;;*==*!!;;;;;!==*;:~~~" << endl;
cout << "**::$*::=::;$;~~~~~~:*=;~~~~~~~~~~~::::::~~~~~~~~:" << endl;
cout << ":;:;$=::=:::;;#*:~~~~~~!$*;::::~~~~~~~~~~~~:~::;!;" << endl;
cout << "::::$;::=:::::::#*~~~~~~~~~~~:;!*******=***!;:~~;;" << endl;
cout << "::::*:::*::::::::;=#*;~~~~~~~~~~~~~~~~~~~~~~~~~:::" << endl;
cout << "::::::::!;::::::::::;;!*=*;;:~~~~~~~~~~~~~~~~~~:*:" << endl;
cout << ":::::::::#*;:::::::::::::::;!**===**!!!;;;;;;!*;;*" << endl;
cout << "::::::::::;!$;:::::::::::::::::::::::::;;::*;::;; " << endl;
cout << ":::::::::::::;*!:::::::::::::::::::::::::;;;:::~  " << endl;
cout << ";::::::::::::::*;::::::::::::::::::::::;!;:::;$   " << endl;
cout << "#;::::::::::::::*;:::::::::::::::::::;*;::::;!:   " << endl;
cout << ".!$:::::::::::::*::::::::;::::::::;*==$====*, :   " << endl;
cout << "  .$::::::::::::==**!!;;;;;;!**=*=;..         !   " << endl;
cout << "   ==::::::::::!;:::::;;;;;::::;!.,=          =   " << endl;
cout << "   ;,*::::::::;$****!!!!!!!*!!:,  .~          =   " << endl;
cout << "  -. .!=;;;:;*$~      ....        ~           !   " << endl;
cout << "  ;     .,-,. :                   ;          .-   " << endl;
cout << " .,           :                  .-          ,    " << endl;
cout << " :            -.                 ~           ;    " << endl;
cout << " ;            ..                 :           *    " << endl;
cout << "												   " << endl;







	//MyClass myclass1('2', 23, "노래듣기");
	//myclass1.ShowInfo();

	//MyClass myclass2 = { 2,6 };

	//MyStruct mystruct1;
	//mystruct1.a = 3;
	//mystruct1.b = 7;

	//MyStruct mystruct2 = { 4,8 };

	//cout << "Myclass1 : " << myclass1.a << "||" << myclass1.b << endl;
	//cout << "Myclass2 : " << myclass2.a << "||" << myclass2.b << endl;
	//cout << "Mystruct1 : " <<  mystruct1.a << "||" << mystruct1.b << endl;
	//cout << "Mystruct2 : " << mystruct2.a << "||" << mystruct2.b << endl;
}

