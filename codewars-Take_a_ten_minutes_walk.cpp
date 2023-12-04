/*
You live in the city of Cartesia where all roads are laid out in a perfect grid. 
You arrived ten minutes too early to an appointment, so you decided to take the opportunity to go for a short walk. 
The city provides its citizens with a Walk Generating App on their phones -- everytime you press the button 
it sends you an array of one-letter strings representing directions to walk (eg. ['n', 's', 'w', 'e']). 
You always walk only a single block for each letter (direction) and you know it takes you one minute to traverse 
one city block, so create a function that will return true if the walk the app gives you will take you exactly ten minutes 
(you don't want to be early or late!) and will, of course, return you to your starting point. Return false otherwise.

Note: you will always receive a valid array containing a random assortment of direction letters 
('n', 's', 'e', or 'w' only). It will never give you an empty array (that's not a walk, that's standing still!).
*/

#include <vector>
#include <iostream>

bool isValidWalk(std::vector<char> walk) {
    if(walk.size() != 10) { return false; }
    int counter = 0;
    for(size_t i = 0; i < walk.size(); ++i)
    {
        if(walk[i] == 'n') { counter += 1;}
        else if(walk[i] == 's') { counter -= 1;}
        else if(walk[i] == 'w') { counter += 10;}
        else if(walk[i] == 'e') { counter -= 10;}
        else{ counter += 1000; }
        
        //std::cout << '\n' << walk[i] << " Counter: " << counter << '\n';  this line helps with testing
    }
    if(counter == 0) { return true; }
    else{ return false; }
}

/* The most clever solution, but not the efficient one:
In this case this is much slower than my solution, because of 4 times of iteration the vector

#include <vector>
#include <algorithm> 

bool isValidWalk(std::vector<char> walk) {
  return walk.size() == 10 and 
         std::count(walk.begin(), walk.end(), 'e') == std::count(walk.begin(), walk.end(), 'w') and
         std::count(walk.begin(), walk.end(), 'n') == std::count(walk.begin(), walk.end(), 's');
}
*/


int main(){
    std::vector<char> V1 {'n','s','n','s','n','s','n','s','n','s'};
    std::vector<char> V2 {'n','s','e','w','n','s','e','w', 's', 'n'};
    std::vector<char> V3 {'n'};
    std::vector<char> V4 {'n','s','n','s','n','s','n','s','n','s'};
    std::vector<char> V5 {'n','s'};
    std::vector<char> V6 {'n','s','n','s','n','s','n','s','n','s','n','s'};
    std::vector<char> V7 {'e','w','e','w','n','s','n','s','e','w'};
    std::vector<char> V8 {'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'};
    std::vector<char> V9 {'n','s','e','w','n','s','e','w','n','s'};
    std::vector<char> V10 {'s','e','w','n','n','s','e','w','n','s'};
    std::vector<char> V11 {'n','s','n','s','n','s','n','s','n','n'};
    std::vector<char> V12 {'e','e','e','w','n','s','n','s','e','w'};

    std::cout << "\nWynik v1 : " << isValidWalk(V1) << std::endl; 
    std::cout << "\nWynik v2: " << isValidWalk(V2) << std::endl; 
    std::cout << "\nWynik v3: " << isValidWalk(V3) << std::endl; 
    std::cout << "\nWynik v4: " << isValidWalk(V4) << std::endl; 
    std::cout << "\nWynik v5 : " << isValidWalk(V5) << std::endl; 
    std::cout << "\nWynik v6: " << isValidWalk(V6) << std::endl; 
    std::cout << "\nWynik v7: " << isValidWalk(V7) << std::endl; 
    std::cout << "\nWynik v8: " << isValidWalk(V8) << std::endl; 
    std::cout << "\nWynik v9: " << isValidWalk(V9) << std::endl; 
    std::cout << "\nWynik v10: " << isValidWalk(V10) << std::endl; 
    std::cout << "\nWynik v11: " << isValidWalk(V11) << std::endl; 
    std::cout << "\nWynik v12: " << isValidWalk(V12) << std::endl; 

    return 0;
}