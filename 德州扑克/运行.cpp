#include"运行.h"
#include "pch.h"
#include <algorithm>
#include <unordered_set>
using namespace std;
#include"玩家.h";
#include"牌类.h"
#include<vector>
#include"card.h"
#include<map>
bool IsStraight(std::vector<card>& a);
bool IsStraightFlush(std::vector<card>& a);
bool IsFourOfAKind(std::vector<card>& a);
bool IsFullHouse(std::vector<card>& a);
bool IsFlush(std::vector<card>& a);
bool IsThreeOfAKind(std::vector<card>& a);
bool IsTwoPairs(std::vector<card>& a);
bool IsOnePair(std::vector<card>& a);
enum HandType {
    HighCard,
    OnePair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush
};
HandType  check(std::vector<card>& a) {
   
    // 检查同花顺
    if (IsStraightFlush(a)) {
        return StraightFlush;
    }
    // 检查四条
    else if (IsFourOfAKind(a)) {
        return FourOfAKind;
    }
    // 检查葫芦
    else if (IsFullHouse(a)) {
        return FullHouse;
    }
    // 检查同花
    else if (IsFlush(a)) {
        return Flush;
    }
    // 检查顺子
    else if (IsStraight(a)) {
        return Straight;
    }
    // 检查三条
    else if (IsThreeOfAKind(a)) {
        return ThreeOfAKind;
    }
    // 检查两对
    else if (IsTwoPairs(a)) {
        return TwoPairs;
    }
    // 检查一对
    else if (IsOnePair(a)) {
        return OnePair;
    }
    // 高牌
    else {
        return HighCard;
    }
}
bool IsStraight(std::vector<card>& a) {
    unordered_set<int> mySet;
    for (const auto& card : a) {
        mySet.insert(static_cast<int>(card.rank));

    }

    if (mySet.size() < 5) {
        return false;
    }
    vector<int> sortedRanks(mySet.begin(), mySet.end());
    sort(sortedRanks.begin(), sortedRanks.end());
    for (int i = sortedRanks.size() - 1; i >= 4; i--) {
        if (sortedRanks[i] - sortedRanks[i - 4] == 4) {
            return true;  // 找到连续的五张牌
        }
    }
    if (sortedRanks.size() >= 5 && sortedRanks.back() == 14 && sortedRanks[0] == 2 && sortedRanks[1] == 3 && sortedRanks[2] == 4 && sortedRanks[3] == 5) {
        return true;
    }
  
        return false;
}
bool IsStraightFlush(std::vector<card>& a) {
    int b = 0, c = 0, d = 0, e = 0;
    std::vector<int> h;
    unordered_set<int> mySet;
    for (int i = 0; i < 7; i++) {
        if (a[i].suit == 0) {
            b++;
        }
        else if (a[i].suit == 1) {
            c++;
        }
        else if (a[i].suit == 2) {
            d++;
        }
        else if (a[i].suit == 3) {
            e++;

        }
    }
    if (b < 5 && c < 5 && d < 5 && e < 5) {
        return false;
    }
    else {
        if (max( c, b, e, d ) == b) {
            for (int i = 0; i < 7; i++) {
                if (a[i].suit == 0) {
                    mySet.insert(static_cast<int>(a[i].rank));
                    }
                }
            }
        else if (max(c, b, e, d) == c) {
            for (int i = 0; i < 7; i++) {
                if (a[i].suit == 1) {
                    mySet.insert(static_cast<int>(a[i].rank));
                }
            }
        }
        else if (max(c, b, e, d) == d) {
            for (int i = 0; i < 7; i++) {
                if (a[i].suit == 2) {
                    mySet.insert(static_cast<int>(a[i].rank));
                }
            }
        }
        else  if (max(c, b, e, d) == e) {
            for (int i = 0; i < 7; i++) {
                if (a[i].suit == 3) {
                    mySet.insert(static_cast<int>(a[i].rank));
                }
            }
        }
     }
    if (mySet.size() < 5) {
        return false;
    }
    std::vector<int> sortedRanks(mySet.begin(), mySet.end());
    std::sort(sortedRanks.begin(), sortedRanks.end());
    for (int i = 0; i <= sortedRanks.size() - 5; ++i) {
        if (sortedRanks[i + 4] - sortedRanks[i] == 4) {
            return true;  // 找到连续的五张牌
        }
    }
    if (sortedRanks.size() >= 5 && sortedRanks.back() == 14 && sortedRanks[0] == 2 && sortedRanks[1] == 3 && sortedRanks[2] == 4 && sortedRanks[3] == 5) {
        return true;
    }

    return false;

 }
bool IsFourOfAKind(std::vector<card>& a){
    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++; 
    }
    for (const auto& pair : rankCount) {
        if (pair.second == 4) {
            return true; 
        }
    }
    return false;
    }
bool IsFullHouse(std::vector<card>& a){
    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    int threeOfAKindCount = 0;
    int pairCount = 0;

    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            threeOfAKindCount++;
        }
        else if (pair.second == 2) {
            pairCount++;
        }
    }
    return (threeOfAKindCount == 1 && pairCount >=1);

}
bool IsFlush(std::vector<card>& a) {
    int b = 0, c = 0, d = 0, e = 0;
    for (int i = 0; i < 7; i++) {
        if (a[i].suit == 0) {
            b++;
        }
        else if (a[i].suit == 1) {
            c++;
        }
        else if (a[i].suit == 2) {
            d++;
        }
        else if (a[i].suit == 3) {
            e++;

        }
    }
    if (b < 5 && c < 5 && d < 5 && e < 5) {
        return false;
    }
    else {
        return true;
    }
}
bool IsThreeOfAKind(std::vector<card>& a) {
    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            return true;
        }
    }
    return false;
}
bool IsTwoPairs(std::vector<card>& a){
    int pairCount = 0;
    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            pairCount++;
        }
    }
    return(pairCount >= 2);
}
bool IsOnePair(std::vector<card>& a) {

    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            return true;
        }
    }
    return false;
}

int findmaxStraight(std::vector<card>& a) {
    unordered_set<int> mySet;
    for (const auto& card : a) {
        mySet.insert(static_cast<int>(card.rank));
    }
        vector<int> sortedRanks(mySet.begin(), mySet.end());
        sort(sortedRanks.begin(), sortedRanks.end());
        for (size_t i = sortedRanks.size() - 1; i >= 4; i--) {
            if (sortedRanks[i] - sortedRanks[i - 4] == 4) {
                return true;  // 找到连续的五张牌
            }
        }
        if (sortedRanks.size() >= 5 && sortedRanks.back() == 14 && sortedRanks[0] == 2 && sortedRanks[1] == 3 && sortedRanks[2] == 4 && sortedRanks[3] == 5) {
            return 5;
        }

}
int findmaxStraightflash(std::vector<card>& a) {
    int b = 0, c = 0, d = 0, e = 0;
    std::vector<int> h;
    unordered_set<int> mySet;
    for (int i = 0; i < 7; i++) {
        if (a[i].suit == 0) {
            b++;
        }
        else if (a[i].suit == 1) {
            c++;
        }
        else if (a[i].suit == 2) {
            d++;
        }
        else if (a[i].suit == 3) {
            e++;

        }
    }
    if (max(c, b, e, d) == b) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 0) {
                mySet.insert(static_cast<int>(a[i].rank));
            }
        }
    }
    else if (max(c, b, e, d) == c) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 1) {
                mySet.insert(static_cast<int>(a[i].rank));
            }
        }
    }
    else if (max(c, b, e, d) == d) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 2) {
                mySet.insert(static_cast<int>(a[i].rank));
            }
        }
    }
    else  if (max(c, b, e, d) == e) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 3) {
                mySet.insert(static_cast<int>(a[i].rank));
            }
        }
    }
    std::vector<int> sortedRanks(mySet.begin(), mySet.end());
    std::sort(sortedRanks.begin(), sortedRanks.end());
    for (int i = sortedRanks.size(); i >=5; --i) {
        if (sortedRanks[i-1] - sortedRanks[i-5] == 4) {
            return sortedRanks[i - 1];  // 找到最大的元素
        }
    }
    if (sortedRanks.size() >= 5 && sortedRanks.back() == 14 && sortedRanks[0] == 2 && sortedRanks[1] == 3 && sortedRanks[2] == 4 && sortedRanks[3] == 5) {
        return 5;
    }
}
struct F {
    int e;
    int b;
};
F result = { 0,0 };
F findmaxFourOfAKind(std::vector<card>& a){
    int maxValue = 0;
    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    for (const auto& pair : rankCount) {
        if (pair.second == 4) {
            result.e = pair.first;
        }
        for (const auto& pair : rankCount) {
            if (pair.first != result.e && pair.first > maxValue) {
                maxValue = pair.first;  // 更新最大值
            }
        }
        return{ result.e,maxValue };
    }
}
F findmaxFullHouse(std::vector<card>& a){
    std::map<int, int> rankCount;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    std::vector<int> threeOfAKind;
    std::vector<int> twoOfAKind;
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            threeOfAKind.push_back(pair.first);  // 将出现次数为3的值加入结果
        }
    }
    result.e= *std::max_element(threeOfAKind.begin(), threeOfAKind.end());
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            twoOfAKind.push_back(pair.first);  // 将出现次数为2的值加入结果
        }
    }
    result.b= *std::max_element(twoOfAKind.begin(), twoOfAKind.end());
    return { result.e , result.b };
}
int findflash(std::vector<card>& a) {
    int b = 0, c = 0, d = 0, e = 0;
    std::vector<int> h;
    for (int i = 0; i < 7; i++) {
        if (a[i].suit == 0) {
            b++;
        }
        else if (a[i].suit == 1) {
            c++;
        }
        else if (a[i].suit == 2) {
            d++;
        }
        else if (a[i].suit == 3) {
            e++;

        }
    }
    if (max(c, b, e, d) == b) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 0) {
                h.push_back(static_cast<int>(a[i].rank));
            }
        }
    }
    else if (max(c, b, e, d) == c) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 1) {
                h.push_back(static_cast<int>(a[i].rank));
            }
        }
    }
    else if (max(c, b, e, d) == d) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 2) {
                h.push_back(static_cast<int>(a[i].rank));
            }
        }
    }
    else  if (max(c, b, e, d) == e) {
        for (int i = 0; i < 7; i++) {
            if (a[i].suit == 3) {
                h.push_back(static_cast<int>(a[i].rank));
            }
        }
    }
    return  *std::max_element(h.begin(), h.end());
}
F findIsThreeOfAKind(std::vector<card>& a) {
    std::map<int, int> rankCount;
    int maxValue = 0;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    std::vector<int> threeOfAKind;
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            threeOfAKind.push_back(pair.first);  // 将出现次数为3的值加入结果
        }
    }
    result.e = *std::max_element(threeOfAKind.begin(), threeOfAKind.end());
    for (const auto& pair : rankCount) {
        if (pair.first != result.e && pair.first > maxValue) {
            maxValue = pair.first;  // 更新最大值
        }
    }
    return{ result.e,maxValue };
}
std::vector<int> findTwoPairs(std::vector<card>& a) {
    std::map<int, int> rankCount;
    int maxValue = 0;
    for (const auto& card :a) {
        rankCount[card.rank]++;
    }
    std::vector<int> pairs;
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            pairs.push_back(pair.first);
        }
    }
    if (pairs.size() >= 2) {
        std::sort(pairs.begin(), pairs.end(), std::greater<int>());
    }
    for (const auto& pair : rankCount) {
        if (pair.first != pairs[1] && pair.first !=pairs[0] && pair.first > maxValue) {
            maxValue = pair.first;  // 更新最大值
        }
    }
    std::vector<int> pairs1 = { pairs[0],pairs[1],maxValue };
    return pairs1;
}
std::vector<int> findOnePair(std::vector<card>& a) {
    std::map<int, int> rankCount;
    int maxValue = 0;
    int i;
    for (const auto& card : a) {
        rankCount[card.rank]++;
    }
    std::vector<int> pairs;
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            i = pair.first;
        }
    }
    for (const auto& pair : rankCount) {
        if (pair.first != i&& pair.first > maxValue) {
            maxValue = pair.first;  // 更新最大值
        }
    }
    std::vector<int> pairs1 = {i,maxValue };
    return pairs1;
}
bool paixu(card&a,card&b) {
    return a.rank > b.rank;
}
bool compairhandtype(std::vector<card>& a, std::vector<card>& b){
    HandType A = check(a);
    HandType B = check(b);
    if (A > B) {
      
        return true;
    }
    else if (A < B) {

   
        return false;
    }
    else {
     
        if (A == StraightFlush) {
            if (findmaxStraightflash(a) > findmaxStraightflash(b)) {
             
                return true;
            }
            else if (findmaxStraightflash(a) < findmaxStraightflash(b)) {
              
                return false;
            }
            else {
           
                return false;
            }
        }
        else if (A == FourOfAKind) {
            if (findmaxFourOfAKind(a).e > findmaxFourOfAKind(b).e) {
                
                return true;
            }
            else if (findmaxFourOfAKind(a).e< findmaxFourOfAKind(b).e) {
              
                return false;
            }
            else {
                if (findmaxFourOfAKind(a).b > findmaxFourOfAKind(b).b) {
                   
                    return true;
                }
                else if (findmaxFourOfAKind(a).b < findmaxFourOfAKind(b).b) {
                    
                    return false;
                }
                else {
              
                    return false;
                }
            }
        }
        else if (A == FullHouse) {
            if (findmaxFullHouse(a).e > findmaxFullHouse(b).e) {
            
                return true;
            }
            else if (findmaxFullHouse(a).e<findmaxFullHouse(b).e) {
            
                return false;
            }
            else {
                if (findmaxFullHouse(a).b > findmaxFullHouse(b).b) {
                
                    return true;
                }
                else if (findmaxFullHouse(a).b < findmaxFullHouse(b).b) {
               
                    return false;
                }
                else {
             
                    return false;
                }
            }

        }
        else if (A == Flush) {
            if (findflash(a) > findflash(b)) {
            
                return true;
            }
            else if (findflash(a) < findflash(b)) {
         
                return false;
            }
            else {
            
                return false;
            }
        }
        else if(A== Straight){
            if (findmaxStraight(a) > findmaxStraight(b)) {
          
                return true;
            }
            else if (findmaxStraight(a) < findmaxStraight(b)) {
          
                return false;
            }
            else {

                return false;
            }
        }
        else if (A== ThreeOfAKind) {
            if (findIsThreeOfAKind(a).e > findIsThreeOfAKind(b).e) {
              
                return true;
            }
            else if (findIsThreeOfAKind(a).e < findIsThreeOfAKind(b).e) {
                
                return false;
            }
            else {
                if (findIsThreeOfAKind(a).b > findIsThreeOfAKind(b).b) {
         
                    return true;
                }
                else if (findIsThreeOfAKind(a).b < findIsThreeOfAKind(b).b) {
                   
                    return false;
                }
                else {
              
                    return false;
                }
            }
        }
        else if (A == TwoPairs) {
            if (findTwoPairs (a)[0]> findTwoPairs(b)[0]) {
           
                return true;
            }
            else if (findTwoPairs(a)[0] < findTwoPairs(b)[0]) {
             
                return false;
            }
            else {
                if (findTwoPairs(a)[1] > findTwoPairs(b)[1] ) {
               
                    return true;
                }
                else if (findTwoPairs(a)[1] < findTwoPairs(b)[1]) {
              
                    return false;
                }
                else {
                    if (findTwoPairs(a)[2] > findTwoPairs(b)[2]) {
          
                        return true;
                    }
                    else if (findTwoPairs(a)[2] <findTwoPairs(b)[2]) {

                        return false;
                    }
                    else {
                 
                        return false;
                    }
                }
            }
        }
        else if (A ==OnePair) {
            if (findOnePair(a)[0] > findOnePair(b)[0]) {
           
                return true;
            }
            else if (findOnePair(a)[0] < findOnePair(b)[0]) {
         
                return false;
            }
            else {
                if (findOnePair(a)[1] > findOnePair(b)[1]) {
            
                    return true;
                }
                else if (findOnePair(a)[1] < findOnePair(b)[1]) {

                    return false;
                }
                else {
      
                    return false;
                }
            }
        }
        else {
            sort(a.begin(), a.end(), paixu);
            sort(b.begin(), b.end(), paixu);
            if (a[0].rank > b[0].rank) {
   
                return true;
            }
            else if (a[0].rank < b[0].rank) {
    
                return false;
            }
            else {
                if (a[1].rank > b[1].rank) {
    
                    return true;
                }
                else if (a[1].rank < b[1].rank) {
  
                    return false;
                }
                else {
                    if (a[2].rank > b[2].rank) {

                        return true;
                    }
                    else if (a[2].rank < b[2].rank) {
     
                        return false;
                    }
                    else {
                        if (a[3].rank > b[3].rank) {
 
                            return true;
                        }
                        else if (a[3].rank < b[3].rank) {

                            return false;
                        }
                        else {
                            if (a[4].rank > b[4].rank) {

                                return true;
                            }
                            else if (a[4].rank < b[4].rank) {

                                return false;
                            }
                            else {

                                return false;
                            }
                        }
                    }
                }
            }
        }
        
    }
}

int  evaluate1 (std::vector<card>& a, std::vector<card>& b)
{
    HandType A = check(a);
    HandType B = check(b);
    if (A > B) {
        return 0;
    }
    else if (A < B) {
        return 1;
    }
    else {
        if (A == StraightFlush) {
            if (findmaxStraightflash(a) > findmaxStraightflash(b)) {
                return 0;
            }
            else if (findmaxStraightflash(a) < findmaxStraightflash(b)) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (A == FourOfAKind) {
            if (findmaxFourOfAKind(a).e > findmaxFourOfAKind(b).e) {
                return 0;
            }
            else if (findmaxFourOfAKind(a).e < findmaxFourOfAKind(b).e) {
                return 1;
            }
            else {
                if (findmaxFourOfAKind(a).b > findmaxFourOfAKind(b).b) {
                    return 0;
                }
                else if (findmaxFourOfAKind(a).b < findmaxFourOfAKind(b).b) {
                    return 1;
                }
                else {
                    return 2;
                }
            }
        }
        else if (A == FullHouse) {
            if (findmaxFullHouse(a).e > findmaxFullHouse(b).e) {
                return 0;
            }
            else if (findmaxFullHouse(a).e < findmaxFullHouse(b).e) {
                return 1;
            }
            else {
                if (findmaxFullHouse(a).b > findmaxFullHouse(b).b) {
                    return 0;
                }
                else if (findmaxFullHouse(a).b < findmaxFullHouse(b).b) {
                    return 1;
                }
                else {
                    return 2;
                }
            }
        }
        else if (A == Flush) {
            if (findflash(a) > findflash(b)) {
                return 0;
            }
            else if (findflash(a) < findflash(b)) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (A == Straight) {
            if (findmaxStraight(a) > findmaxStraight(b)) {
                return 0;
            }
            else if (findmaxStraight(a) < findmaxStraight(b)) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (A == ThreeOfAKind) {
            if (findIsThreeOfAKind(a).e > findIsThreeOfAKind(b).e) {
                return 0;
            }
            else if (findIsThreeOfAKind(a).e < findIsThreeOfAKind(b).e) {
                return 1;
            }
            else {
                if (findIsThreeOfAKind(a).b > findIsThreeOfAKind(b).b) {
                    return 0;
                }
                else if (findIsThreeOfAKind(a).b < findIsThreeOfAKind(b).b) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        else if (A == TwoPairs) {
            if (findTwoPairs(a)[0] > findTwoPairs(b)[0]) {
                return 0;
            }
            else if (findTwoPairs(a)[0] < findTwoPairs(b)[0]) {
                return 1;
            }
            else {
                if (findTwoPairs(a)[1] > findTwoPairs(b)[1]) {
                    return 0;
                }
                else if (findTwoPairs(a)[1] < findTwoPairs(b)[1]) {
                    return 1;
                }
                else {
                    if (findTwoPairs(a)[2] > findTwoPairs(b)[2]) {
                        return 0;
                    }
                    else if (findTwoPairs(a)[2] < findTwoPairs(b)[2]) {
                        return 1;
                    }
                    else {
                        return 2;
                    }
                }
            }
        }
        else if (A == OnePair) {
            if (findOnePair(a)[0] > findOnePair(b)[0]) {
                return 0;
            }
            else if (findOnePair(a)[0] < findOnePair(b)[0]) {
                return 1;
            }
            else {
                if (findOnePair(a)[1] > findOnePair(b)[1]) {
                    return 0;
                }
                else if (findOnePair(a)[1] < findOnePair(b)[1]) {
                    return 1;
                }
                else {
                    return 2;
                }
            }
        }
        else {
            sort(a.begin(), a.end(), paixu);
            sort(b.begin(), b.end(), paixu);
            if (a[0].rank > b[0].rank) {
                return 0;
            }
            else if (a[0].rank < b[0].rank) {
                return 1;
            }
            else {
                if (a[1].rank > b[1].rank) {
                    return 0;
                }
                else if (a[1].rank < b[1].rank) {
                    return 1;
                }
                else {
                    if (a[2].rank > b[2].rank) {
                        return 0;
                    }
                    else if (a[2].rank < b[2].rank) {
                        return 1;
                    }
                    else {
                        if (a[3].rank > b[3].rank) {
                            return 0;
                        }
                        else if (a[3].rank < b[3].rank) {
                            return 1;
                        }
                        else {
                            if (a[4].rank > b[4].rank) {
                                return 0;
                            }
                            else if (a[4].rank < b[4].rank) {
                                return 1;
                            }
                            else {
                                return 2;
                            }
                        }
                    }
                }
            }
        }
    }
}

  





