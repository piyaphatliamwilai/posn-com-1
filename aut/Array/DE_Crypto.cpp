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

// Recursive function to count all valid pattern matches
int findMatches(int currentDay, int currentPatternIndex, int allowSkip, int skipAlreadyUsed, int patternLength) {
    // Base case: we've matched the entire pattern
    if (currentPatternIndex == patternLength) {
        return 1;
    }
    
    // No more days to compare
    if (currentDay >= numDays - 1) {
        return 0;
    }
    
    int totalMatches = 0;
    
    // Option 1: Try matching the next pattern element without skipping
    // Compare consecutive days (currentDay and currentDay + 1)
    int direction = getDirection(currentDay, currentDay + 1);
    if (direction == searchPattern[currentPatternIndex]) {
        totalMatches += findMatches(currentDay + 1, currentPatternIndex + 1, allowSkip, skipAlreadyUsed, patternLength);
    }
    
    // Option 2: Try matching with skip (if skipping is allowed and not already used)
    // Skip one day and compare (currentDay and currentDay + 2)
    if (allowSkip == 1 && skipAlreadyUsed == 0 && currentDay + 2 < numDays) {
        direction = getDirection(currentDay, currentDay + 2);
        if (direction == searchPattern[currentPatternIndex]) {
            totalMatches += findMatches(currentDay + 2, currentPatternIndex + 1, allowSkip, 1, patternLength);
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
        
        int totalMatches = 0;
        
        // Try each starting position
        for (int startDay = 0; startDay < numDays - 1; startDay++) {
            // Count all pattern matches starting from this day
            totalMatches += findMatches(startDay, 0, allowSkip, 0, patternLength);
        }
        
        cout << totalMatches << "\n";
    }
    
    return 0;
}
