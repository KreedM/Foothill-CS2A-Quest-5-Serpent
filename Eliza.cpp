// Derek Meng

// Eliza.cpp

// 2a.Lab-05-Eliza

#include <iostream>
#include <sstream>

using namespace std;

string lispify(string s) {
  string lisped = "";

  for(size_t i = 0; i < s.length(); i++) {
    if(s[i] == 's')
      lisped += "th";
    else if(s[i] == 'S') 
      lisped += "Th";
    else
      lisped += s[i];
  }

  return lisped;
}

string rotate_vowels(string& s) {
  for(size_t i = 0; i < s.length(); i++) {
    if(s[i] == 'a') 
      s[i] = 'e';
    else if(s[i] == 'e') 
      s[i] = 'i';
    else if(s[i] == 'i') 
      s[i] = 'o';
    else if(s[i] == 'o') 
      s[i] = 'u';  
    else if(s[i] == 'u') 
      s[i] = 'a';
    else if(s[i] == 'A') 
      s[i] = 'E';
    else if(s[i] == 'E') 
      s[i] = 'I';
    else if(s[i] == 'I') 
      s[i] = 'O';
    else if(s[i] == 'O') 
      s[i] = 'U';
    else if(s[i] == 'U') 
      s[i] = 'A';
  }

  return s;
}

void enter() {
  cout << "What?\n";

  string input;

  while(true) {
    getline(cin, input);

    if(input.length() == 0) {
      cout << "What?\n";
     
      continue;
    }

    cout << "    " << input << endl << endl;

    if(input.find("!") != string::npos) {
      cout << "OMG! You don't say!! " << input << "!!!!!\n";
      
      continue;
    }

    if(input.find("why") != string::npos || input.find("what") != string::npos) {
      cout << "I'm sorry, I don't like questions that contain what or why.\n";
      
      continue;
    }

    if(input.find("s") != string::npos) {
      cout << "Interethting. When did you thtop thtopping your thibilanth?\n";
      cout << lispify(input) << "! Sheesh! Now what?\n";

      continue;
    }

    if(input.compare("bye") == 0 || input.compare("Bye") == 0 || input.compare("quit") == 0 || input.compare("Quit") == 0) {
      cout << "Ok Bye. Nice being a force of change in your life.\n";

      break;
    }

    if(rand() % 10 > 7) 
      cout << "Huh? Why do you say: " << input << "?\n";
    else 
      cout << rotate_vowels(input) << "?\n";
  }
}