//A pangram is a sentence that contains every single letter of the alphabet at least once. For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters A-Z at least once (case is irrelevant).

//Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.

//Lösningen: 



#include <ctype.h>   // För : isalpha, tolower, toupper, isdigit 
#include <stdbool.h> // För : bool, true, false
bool is_pangram(const char *str_in){
  int match=0;
  char alpha [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  for(int i=0;str_in[i] != '\0';i++){  // We are going to loop untill we reach the end of the string \0. sizeof pointer is going to give us 8 or 4 depends on the sys.
    for(int j=0;j<sizeof(alpha);j++){
      if(tolower((unsigned char)str_in[i])==alpha[j]){ // Unsigned because : ctype.h library. Som systems handle char as signed. Means negative. This can crash tolower func.
        alpha[j]= 1;
        match++;
        break; //if we got match, there is no need to continue looking inside the alphabet string. break; take us out of this inner loop.
      }
    }
  }
  if(match == 26){
    return true;
  }
  else{
    return false;
  }


}

//Mer utvecklad lösningar kommer i framtiden.
