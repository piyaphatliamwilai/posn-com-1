#include <iostream>
using namespace std;

int numDays, numQueries;
int coinPrices[100005];
int searchPattern[100005];

int getDirection(int fromDay, int toDay) {
    if (coinPrices[toDay] > coinPrices[fromDay]) return 1;
    if (coinPrices[toDay] < coinPrices[fromDay]) return -1;
    return 0;
}

int countPatternMatches(int patternLength, int allowSkip) {
    int totalMatches = 0;
    
    // Try every possible starting position
    for (int startDay = 0; startDay < numDays - 1; startDay++) {
        // Track all possible states we need to explore
        // Each state stores: (current day, pattern index, skip used flag)
        int dayState[10000];
        int patternState[10000];
        int skipState[10000];
        int stateCount = 1;
        
        dayState[0] = startDay;
        patternState[0] = 0;
        skipState[0] = 0;
        
        // Process all states
        for (int stateIdx = 0; stateIdx < stateCount; stateIdx++) {
            int currentDay = dayState[stateIdx];
            int currentPatternIndex = patternState[stateIdx];
            int skipAlreadyUsed = skipState[stateIdx];
            
            // Success: matched entire pattern
            if (currentPatternIndex == patternLength) {
                totalMatches++;
                continue;
            }
            
            // Failure: no more days to compare
            if (currentDay >= numDays - 1) {
                continue;
            }
            
            // Option 1: Match without skipping (consecutive days)
            int direction = getDirection(currentDay, currentDay + 1);
            if (direction == searchPattern[currentPatternIndex]) {
                dayState[stateCount] = currentDay + 1;
                patternState[stateCount] = currentPatternIndex + 1;
                skipState[stateCount] = skipAlreadyUsed;
                stateCount++;
            }
            
            // Option 2: Match with skip (if allowed and not used)
            if (allowSkip == 1 && skipAlreadyUsed == 0 && currentDay + 2 < numDays) {
                direction = getDirection(currentDay, currentDay + 2);
                if (direction == searchPattern[currentPatternIndex]) {
                    dayState[stateCount] = currentDay + 2;
                    patternState[stateCount] = currentPatternIndex + 1;
                    skipState[stateCount] = 1;
                    stateCount++;
                }
            }
        }
    }
    
    return totalMatches;
}

int main() {
    cin >> numDays >> numQueries;
    
    for (int i = 0; i < numDays; i++) {
        cin >> coinPrices[i];
    }
    
    for (int q = 0; q < numQueries; q++) {
        int patternLength, allowSkip;
        cin >> patternLength >> allowSkip;
        
        for (int i = 0; i < patternLength; i++) {
            cin >> searchPattern[i];
        }
        
        cout << countPatternMatches(patternLength, allowSkip) << "\n";
    }
    
    return 0;
}
