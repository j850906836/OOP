#include "HuffmanTree.h"
#include <iostream>
#include <string>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;

int main(){
	//HuffmanTree t1("c-c-c^@^--cccC-C-C-C-^c@");
	//t1.printMap();
	//cout << t1.encode("c-c-c-c-@@@@C----") << endl;
	//cout << t1.encode("uhashd87781") << endl;
	
	HuffmanTree t1("yaaaaay!");
	cout << "[test1] [40%, 5% each]" << endl;
	
	cout << "[test1-1] [expected] 10";
	cout << "[result] " << t1.encode("y") << endl;
	
	cout << "[test1-2] [expected] 0";
	cout << "[result] " << t1.encode("a") << endl;
	
	cout << "[test1-3] [expected] 11";
	cout << "[result] " << t1.encode("!") << endl;
	
	cout << "[test1-4] [expected] 01001001111";
	cout << "[result] " << t1.encode("ayaya!!") << endl;
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);
	
	cout << "[test1-5] [expected] yyyyaaaayyyy";
	cout << "[result] " << t1.decode("10101010000010101010") << endl;
	
	cout << "[test1-6] [expected] print error message";
	cout << "[result] ";
	t1.encode("E");
	cout << endl;
	
	cout << "[test1-7] [expected] print error message";
	cout << "[result] ";
	t1.decode("101");
	cout << endl;
	
	cout << "[test1-8] [expected] print error message";
	cout << "[result] ";
	t1.decode("111111111");
	cout << endl;
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);
	
	
	HuffmanTree t2("it-is-a-long-established-fact-that-a-reader-will-be-distracted-by-the-readable-content-of-a-page-when-looking-at-its-layout.-the-point-of-using-lorem-ipsum-is-that-it-has-a-more-or-less-normal-distribution-of-letters,-as-opposedd-to-using-cooontent-here,-content-here,-makkkingg-it-look-like-readable-english.-many-desktop-publishing-packages-and-web-page-editors-now-use-lorem-ipsum-as-their-default-model-text,-and-a-search-ffffor-lorem-ipsum-will-uncovver-many-web-sites-still-in-their-infancy.-various-versions-have-evolved-over-the-years,-sometimes-bbbbyyyyyyyyyy-accident-sometimes-on-ppurpose-iiinjjected-humour-and-the-alike-ggggggggguuuuuudddrnaaaet.");
	cout << "[test2] [40%, 10% each]" << endl;
	string ans, outp;
	
	cout << "[test2-1]" << endl;
	ans = "100001011001000000010100010010001111111011000111001000000011101000101110010100111001101101010000001110001101100110111000110111100000011110011101001011000010010001110001110001111100000111000110011011101001000111110000110111001010000101110111111010010001111011111100000111000101100110010100001000111011000010001001100001011111110000100100101111110101000001000010011110000010010000000010110101101110011001010000011101000000011110011101001011000011111010100000110000001110100001011001010001101100000011110110110100111101000001101001010000011111000011011100101000010110110000101100110010100000100100000010010011111111011000001011001010000011010011001001100010000011111110010111010010000001100001001101100011110000101101000010110010010101111110";
	outp = t2.encode("our-project-compiles-cleanly-with-gcc,-clang,-and-mingw.-i-had-one-of-my-guys-try-to-build-it-with-vs-a-couple-weeks-ago,-and-he-had-to-give-up-after-just-a-few-hours.");
	cout << "[test result]" << endl;
	if(ans == outp) cout << "OK" << endl;
	else cout << "Wrong!" << endl;
	
	cout << "[expected]" << endl;
	cout << ans << endl;
	cout << "[output]" << endl;
	cout << outp;
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);
	
	cout << "[test2-2]" << endl;
    ans = "if-you-ever-get-cold,-stand-in-the-corner-of-a-room-for-a-while.-they-are-usually-ninety-degrees.";
	outp = t2.decode("011110011000011110100001011000110111110110001000001001011001000000011101000001100101000111110001010010001101110010100000111111000001001011011000000111010000010011101100010000010001001100000110000001001000100010111000100110100000100000011000000111101011001110011011011111100000100101101101111000001100010011000001011101001011011000110001101111000011100111111011001001111000001010110100100010011011010101111110");
	cout << "[test result]" << endl;
	if(ans == outp) cout << "OK" << endl;
	else cout << "Wrong!" << endl;
	
	cout << "[expected]" << endl;
	cout << ans << endl;
	cout << "[output]" << endl;
	cout << outp;
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);
	
	cout << "[test2-3]" << endl;
	cout << "[expected] print error message" << endl;
	cout << "[output]" << endl;
	t2.encode("The-plot-for-Mega-Man-X4-is-presented-by-both-fully-animated-full-motion-video-(FMV)-cutscenes-and-in-game-text.-The-storyline-differs-slightly-depending-on-whether-the-player-chooses-Mega-Man-X-or-Zero.");
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);
	
	cout << "[test2-4]" << endl;
	cout << "[expected] print error message" << endl;
	cout << "[output]" << endl;
	outp = t2.encode("he-spent-four-days-coming-up-with-the-initial-blueprint,-but-was-told-by-his-supervisor-to-go-back-and-try-again.-After-tinkering-with-the-armor-parts,-he-noticed-that-attaching-them-in-specific-ways-made-it-look-like-an-airplane.");
	t2.decode(outp+"1111111");
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);	
	
		
	// If the program prints an error message when building HuffmanTree t3, t3.encode will not be tested
	cout << "[test3] [10%, 5% each]" << endl;
	cout << "[test3-1]" << endl;
	cout << "[expected] print error message" << endl;
	cout << "[output]" << endl;
	HuffmanTree t3("AAAA");
	t3.encode("A");
	
	// If the program prints an error message when building HuffmanTree t4, t4.encode will not be tested
	cout << "[test3-2]" << endl;
	cout << "[expected] print error message" << endl;
	cout << "[output]" << endl;
	HuffmanTree t4("");
	t4.encode("A");
	
	cout << "[test4: memory leak test] [10%]" << endl;
	cout << "use Valgrind to see if there are memory leaks." << endl;
	
	cout << endl << "press any key to continue..." << endl;
	fgetc(stdin);
	cout << "--------- program end ---------" << endl;
	return 0;
}