/*
Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point

A single die can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)

In some languages, it is possible to mutate the input to the function. This is something that you should never do. If you mutate the input, you will not be able to pass all the tests.

*/

#include <vector>
#include <iostream>

int score(const std::vector<int>& dice) {
    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, result = 0;
    for(auto el : dice)
    {
        switch (el)
        {
        case 1:
            ++counter1;
            break;
        case 2:
            ++counter2;
            if (counter2 == 3) { result += 200; }
            break;
        case 3:
            ++counter3;
            if (counter3 == 3) { result += 300; }
            break;
        case 4:
            ++counter4;
            if (counter4 == 3) { result += 400; }
            break;
        case 5:
            ++counter5;
            break;
        case 6:
            ++counter6;
            if (counter6 == 3) { result += 600; }
            break;
        
        default:
            break;
        }
    }
    if(counter1 > 0)
    {
        if      (counter1 == 1) { result += 100; }
        else if (counter1 == 2) { result += 200; }
        else if (counter1 == 3) { result += 1000; }
        else if (counter1 == 4) { result += 1100; }
        else                    { result += 1200; }
    }

    if(counter5 > 0)
    {
        if      (counter5 == 1) { result += 50; }
        else if (counter5 == 2) { result += 100; }
        else if (counter5 == 3) { result += 500; }
        else if (counter5 == 4) { result += 550; }
        else                    { result += 600; }
    }
    return result;
}

int main(){
    std::vector<int> vec = {2, 3, 4, 6, 2};
    std::vector<int> vec2 = {2, 4, 4, 5, 4};

    std::cout << score(vec) << '\n';
    std::cout << score(vec2) << '\n';

    return 0;
}

/* The most clever solutions:
BRILLIANT!
#include <vector> 

int score(const std::vector<int>& dice) {
  unsigned cs[7] = {};
  for (auto d : dice)
    cs[d]++;
  return
    cs[1] / 3 * 1000 + cs[6] / 3 * 600 + cs[5] / 3 * 500 +
    cs[4] / 3 * 400 + cs[3] / 3 * 300 + cs[2] / 3 * 200 +
    cs[1] % 3 * 100 + cs[5] % 3 * 50;
}


#include <vector>

int score(const std::vector<int>& dice) 
{
  int score = 0;
  int count[7] = { 0 };
  for (auto v : dice)
    if (++count[v] == 3)
    {
      score += (v == 1) ? 1000 : v * 100;
      count[v] = 0;
    }
  score += count[1] * 100;
  score += count[5] * 50;
  return score;
}

*/