#include <iostream>

using namespace std;

// Complete the isValid function below.
// Solution from Leetcode problem

string isValid(string s) {

    int arr[26] = {0};
    int counter = 0;

    for(int i = 0; i < s.length(); i++)
        arr[s[i] - 'a']++;

    int minfr = 100000, maxfr = 0;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > maxfr && arr[i] != 0)
            maxfr = arr[i];
        if(arr[i] < minfr && arr[i] != 0)
            minfr = arr[i];
    }
    int n = sizeof(arr)/sizeof(arr[0]); 
    sort(arr, arr+n);
    // Find the smallest frequency in the sorted array, other than 0 of course
    int j=0;
    while(arr[j]==0){
        j++;
    }

    int countermin = arr[j], countermax = arr[25];
    // if largest and smallest frequencies are the same, the whole array has the same frequency
    if(countermin == countermax)
        return "YES";
    // if the frequencies are only one apart, it can be removed and there is only largest frequenciy
    // if the smallest frequency is 1 and it is the only one that is not equal to the largest,
    // then the result is succuessful.
    if(((countermax - countermin == 1) && (countermax > arr[24])) ||
            (countermin == 1) && (arr[j+1] == countermax))
            return "YES";
    return "NO";
    // for(int i = 0; i < 26; i++)
    // {
    //     if(arr[i] == maxfr)
    //         countermax++;
    //     if(arr[i] == minfr)
    //         countermin++;
    //     cout << arr[i];
    // }
    // for(int i = 0; i < 26; i++)
    // {
    //     if(arr[i] != maxfr && arr[i] != minfr && arr[i] != 0)
    //         return "NO";
    // }
    // if(maxfr == 1 && 1 != minfr)
    //     return "YES";
    // if(maxfr != 1 && 1 == minfr)
    //     return "YES";    
    // if(maxfr == minfr)
    //     return "YES"; 
    // if(countermax > 1 && countermin > 1)
    //     return "NO";
    // if(maxfr - minfr > 1)
    //     return "NO";
      
    // //cout << endl << counter << endl;
    
    // if(counter > 1)
    //     return "NO";
    // return "YES";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
