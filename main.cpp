#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std; 

void setup();
void select_operation();
void remove();

int main(){

   cout << "This program is made to install Tor Browser quickly and easily. If this program causes any damage you are responsible for it. I am not responsible for any damage that may occur. If you accept this, you can continue." << endl << "1)Agree" << endl << "2)Disagree" << endl << "USER>> ";
   int usr;
   cin >> usr;
    if(usr==1){
        system("clear");
        //cout << "Positive output" << endl;
        select_operation();
        
        
    }else if(usr==2){
        system("clear");
        cout << "Unable to continue." << endl << "Exitting..." << endl;
        exit(0);
    }
   
    return 0;
}

void select_operation(){
    
    cout << "Please select an operation to continue:" << endl << "1)Setup Tor Browser" << endl << "2)Remove Tor Browser" << endl;
    int usr;
    cout << "USER>> ";
    cin >> usr;
    
    if(usr==1){
        setup();
        
    }else if(usr==2){
        remove();
    }
    
    
}


void remove(){
    system("clear");
    
    /*
    system("rm -rf ~/.tor");
    cout << "Tor Browser removed from your system." << endl;
    */
    
    string linux_home = getenv("HOME");
    
    fstream ffile;
    ffile.open(linux_home+"/.tor/Browser/libnssdbm3.so");
    if(ffile.fail()) {
        cout << "Tor Browser not found in ~/.tor" << endl << "Please check your filesystem and make sure you don't renamed your .tor directory in your home(/home/username = ~/)" << endl << "Exiting..." << endl;
    }else{
        system("rm -rf ~/.tor");
        cout << "Tor Browser removed from your system." << endl;
    }
    
    
}


void setup(){
    string linux_home = getenv("HOME");
    
    fstream ffile;
    ffile.open(linux_home+"/.tor/Browser/libnssdbm3.so");
    if(ffile.fail()){}else{
        cout << "Tor has already been installed on your system." << endl << "You can run remove function." << endl << "Exiting..." << endl;
        exit(0);
    }
    
    system("clear");
    cout << "Tor Setup Tool by 0rbianta" << endl;
    system("wget https://dist.torproject.org/torbrowser/9.5.4/tor-browser-linux64-9.5.4_en-US.tar.xz");
    ffile.open("tor-browser-linux64-9.5.4_en-US.tar.xz");
    if(ffile.fail()) {
        cout << "Tor Browser is blocked in your country." << endl << "Exiting..." << endl;
        exit(0);
    }
    cout << "Tor Browser files downloaded from https://dist.torproject.org/torbrowser/9.5.4/tor-browser-linux64-9.5.4_en-US.tar.xz" << endl;
    system("clear");
    cout << "Decompressing setup files..." << endl;
    sleep(1);
    int t1 = system("tar -Jxvf tor-browser-linux64-9.5.4_en-US.tar.xz");
    cout << t1 << endl;
    system("clear");
    cout << "Decompress complete. Next step is move tor files to home directory" << endl;
    sleep(2);
    int t2 = system("mv tor-browser_en-US ~/.tor");
    system("clear");
    sleep(3);
    int t3 = system("exec ~/.tor/Browser/start-tor-browser &");
    sleep(1);
    int t4 = system("killall -9 firefox.real");
    int t5 = system("mv ~/.tor/start-tor-browser.desktop ~/");
    
    /*
    //Output file
    ofstream out_file;
    out_file.open("~/tor_setup_output.txt");
    out_file << t1 << endl << t2 << endl << t3 << endl << t4 << endl << t5 << endl << "-----------------------" << endl << "Tor setup tool by 0rbianta";
    out_file.close();
    */
    
    
    system("clear");
    //cout << "Setup complete!" << endl << "Details:" << endl << " * Tor source file: ~/.tor" << endl << " * Tor shortcut location: ~/start-tor-browser.desktop" << endl << " * Setup output file: ~/tor_setup_output.txt" << endl;
    
    cout << "Setup complete!" << endl << "Details:" << endl << " * Tor source file: ~/.tor" << endl << " * Tor shortcut location: ~/start-tor-browser.desktop" << endl;
    
    cout << "Thanks for using 0rbianta's tool. Follow me on media:" << endl << "GitHub: 0rbianta" << endl << "Twitter: 0rbianta" << endl <<"And nothing else. I don't have too much social media accounts. I'm not a virtual social human." << endl;

    
}
