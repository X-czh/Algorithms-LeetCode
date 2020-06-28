// Time complexity: O(day + month + year).
// Space complexity: O(1).

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int day_of_week = 5;
        
        for (int i = 1971; i < year; ++i) {
            if (i % 4 == 0) { // 2000 is leap Year, 2100 not
                day_of_week += 366;
            } else {
                day_of_week += 365;
            }
            day_of_week %= 7;
        }
        
        vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 4 == 0) months[1] = 29; // 2000 is leap Year, 2100 not
        for (int i = 1; i < month; ++i) {
            day_of_week += months[i - 1];
            day_of_week %= 7;
        }
        
        for (int i = 1; i < day; ++i) {
            ++day_of_week;
            day_of_week %= 7;
        }
        
        vector<string> week_days{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return week_days[day_of_week];
    }
};
