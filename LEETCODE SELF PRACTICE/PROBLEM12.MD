DATE: 18-02-2024

## Problem 12: [ Meeting Rooms III (Leetcode-2402) ](https://leetcode.com/problems/meeting-rooms-iii)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

You are given an integer `n`. There are `n` rooms numbered from `0` to `n - 1`.

You are given a 2D integer array `meetings` where `meetings[i] = [starti, endi]` means that a meeting will be held during the **half-closed** time interval `[starti, endi)`. All the values of `starti` are **unique**.

Meetings are allocated to rooms in the following manner:

1. Each meeting will take place in the unused room with the lowest number.
2. If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
3. When a room becomes unused, meetings that have an earlier original start time should be given the room.

Return the `number` of the room that held the most meetings. If there are multiple rooms, return the room with the `lowest number`.

- A **half-closed interval** `[a, b)` is the interval between a and b including a and not including b.

## Examples

- Example 1:

```bash
Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0.
```

Example 2:

```bash
Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1.
```

Example 3:

```bash
Input: n = 3, meetings = [[8,15],[9,12],[7,13],[5,18],[3,10],[1,5]]
Output: 0
```

## Constraints:

1. `1 <= n <= 100`
2. `1 <= meetings.length <= 10^5`
3. `meetings[i].length == 2`
4. `0 <= starti < endi <= 5 * 10^5`
5. All the values of `starti` are **unique**.

**Companies**:
[Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:

- [Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)
- [Meeting Rooms II (Easy)](https://leetcode.com/problems/meeting-rooms-ii/)
- [Maximum Number of Events That Can Be Attended (Easy)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)
- [Find Servers That Handled Most Number of Requests (Easy)](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)
- [Maximum Number of Events That Can Be Attended II (Easy)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

## Solution 1

```cpp
/*
Optimal Approach:
Time complexity: O(N Log N)
Space complexity: O(N)
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Booking array to keep track of the number of meetings each person attends
        vector<int> bookings(n,0);
        // Times array to keep track of the end time of each person's last meeting
        vector< long long > times(n,0);
        // Sort the meetings based on their start times
        sort(meetings.begin(),meetings.end());

        // For each meeting, we find the person who has the earliest available time slot to attend the meeting
        for(int i=0;i<meetings.size();i++){
            int startTime = meetings[i][0];
            int endTime = meetings[i][1];

            // Initially all rooms are free in meeting
            bool isRoomBusy = false;
            int lowerRoom = -1;
            long long waitingDuration = 1e18;

            // Traverse to the each room for each meeting one by one
            for(int j=0;j<n;j++){

                // Find earliest available time slot to attend the meeting
                if(times[j]<waitingDuration){
                    waitingDuration = times[j];
                    lowerRoom = j;
                }

                // If there's a person available, we assign them to attend the
                // meeting and update their end time
                if(times[j] <= startTime){
                    isRoomBusy = true;
                    bookings[j]++;
                    times[j] = endTime;
                    break;
                }
            }

            // If no person is available, we find the person who has the earliest end time
            // among all persons and assign them to attend the meeting. We also update their
            // end time accordingly.
            if(isRoomBusy == false){
                bookings[lowerRoom]++;
                times[lowerRoom] += endTime - startTime;
            }
        }

        // After processing all meetings, we find the person who attended
        // the maximum number of meetings
        int maxBookings = INT_MIN;
        int lowerIndex = -1;
        for(int i = 0; i < n; i++){
            if(bookings[i]>maxBookings){
                maxBookings = bookings[i];
                lowerIndex = i;
            }
        }

        // We return the lowerIndex of the person who attended the most meetings
        return lowerIndex;
    }
};
```
