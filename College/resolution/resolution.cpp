#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>

using namespace std;

string hash(string s) {
    string t = s;
    for (int i = 0; i < s.size(); i++) {
        t[i] = (t[i]+1) % 128;
    }
    return t;
}

string unhash(string s) {
    string t = s;
    for (int i = 0; i < s.size(); i++) {
        t[i] = (t[i]-1) % 128;
    }
    return t;
}

int main() {
    cout << "Please enter password in order to see Coco's 2015 resolution" << endl;
    cout << "Here are some hints about the password. The password" << endl;
    cout << "1. has 12 letters ALL IN LOWER CASE, with no space" << endl;
    cout << "2. is a complete sentence" << endl;
    cout << "3. is what I want to say to you" << endl;
    cout << "4. has mutliple correct answers (exactly 3 in fact)" << endl;

    string s;
    string hashed = "Ifbmui;^K2/!Ep!opu!mfu!nz!fzft!hfu!xpstf\"\"!Uibu!nfbot!J!dboopu!fyibvtu!nz!fzft/!J!nvtu!tujdl!up!hppe!ibcjut/^K3/!Mptf!xfjhiu\"\"!Dvssfoumz!J!xfjhi!bspvoe!65/6!lh!sjhiu!opx/!Nz!hpbm!jt!up!sfbdi!61!lh\"!Uibu!tqfmmt!gps!ifbmuiz!boe!xfmm.dpouspmmfe!ejfu!boe!dpotubou!fyfsdjtf\"^KTdippm;^K2/!Dpoujovf!boe!gjojti!uif!boespje!bqq/!Jo!gbdu!uifsf!bsf!fyjtujoh!tjnjmbs!bqqt!jo!uif!bqq!tupsf-!cvu!op!nbuufs!xifuifs!xf!xpvme!nblf!uif!bqq!hppe!fopvhi!up!qvu!ju!jo!uif!bqq!tupsf-!J!xpvme!tujmm!mjlf!up!tff!b!hppe!gvodujpobm!bqq/^K3/!Cf!cfuufs!bu!dpejoh\"!Ep!npsf!dpefgpsdft!ps!dpnqfujujpo!qsphsbnnjoh!qspcmfnt/!Bu!mfbtu!pof!qfs!xffl/^K4/!Sfbe!npsf!cpplt\"\"!Qmfbtf!sfbe!pof!cppl!b!npoui-!kvtu!mjlf!zpvs!njeemf!tdippm\"^K5/!Cf!npsf!fyqptfe!up!ofxt-!ftqfdjbmmz!qpmjujdt\"^KDbsffs;^K2/!Efdjef!xijdi!ufbn!up!hp!jo!Hpphmf!boe!ibwf!b!hppe!tubsu!jo!dbsffs\"^K3/!Cftjeft!xpsl-!J!nvtu!ibwf!b!tjef!qspkfdu\"\"^KMjgf;^K2/!Usbwfm!npsf!jo!Fvspqf\"\"\"!Nbobhf!nz!ujnf!xfmm!boe!nblf!nfbojohgvm!usjqt\"^K3/!Mfbso!tpnf!Hfsnbo!dvjtjof\"!J!tipvme!tubsu!gjmmjoh!nz!sfdjqf!cppl\"!J!pomz!ibe!pof!fousz^K4/!Cf!b!cfuufs!qipuphsbqifs\"!Ublf!npsf!qjduvsft!boe!cf!cfuufs!bu!qipuptipq\"!Mfbso!npsf!qipuphsbqiz!ufdiojrvft!boe!sfbe!npsf!qipuphsbqiz!tuvgg/^K5/!Cf!npsf!pshboj{fe!jo!hfofsbm/!Dmfbo!sppn!podf!b!xffl/!Lffq!gjmft!boe!gpmefst!pshboj{fe/^KCfbvuz;^K2/!Cfuufs!tljo-!cfuufs!mjgf\"!Sfnfncfs!up!ep!tljodbsf!fwfsz!ebz/^K3/!Bmxbzt!esftt!dmfbo!boe!xfmm/^KGjobodf;^K2/!Mfbso!up!nbobhf!nz!npofz\"!Bu!mfbtu!J!tipvme!ipx!nvdi!J!spvhimz!tqfoe!fbdi!npouiで!Ftqfdjbmmz!bgufs!J!nblf!npofz!boe!cfdpnf!foujsfmz!gjobodjbmmz!joefqfoefou-!J!tipvme!sfbmmz!lopx!gjobodjbm!joqvu!boe!pvuqvu\"!Ju!jt!cfuufs!up!lffq!bo!bddpvou!cppl/";
    cin >> s;
    string value = hash(s);
    while (1) {
        if (hash(s) == "ibqqzofxzfbs" ||
            hash(s) == "jmjlfzpvbmpu" ||
            hash(s) == "zpvbsfbxftpnf") {
            cout << endl;
            cout << unhash("Dpohsbuvmbujpot\"\"\"!Zpv!hvttfe!ju!sjhiu\"") << endl;
            cout << unhash("Kvtu!dsfbufe!b!gjmf!obnfe!sftpmvujpo/uyu\"!)tpssz!ju!dpoubjot!tpnf!voeftjsbcmf!dibsbdufst!cvu!J!ibwf!usjfe!nz!cftu\"!J!nbef!tvsf!zpv!dboopu!difbu!cz!mppljoh!bu!uif!fyfdvubcmf") << endl;
            ofstream fout("resolution.txt");
            fout << unhash(hashed) << endl;
            cout << unhash("Ibqqz!Ofx!Zfbs!up!Ebojfm\"\"\"\"") << endl;
            break;
        }
        cout << "Nice try! But try again :D" << endl;
        cin >> s;
    }
    return 0;
}
