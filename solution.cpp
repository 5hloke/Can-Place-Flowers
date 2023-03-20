// Better solutions would be a recursive one - Would be significatnly faster than this one.
// Create two functions to recursively iterate the odd and even indices of the array based on the result from the previous call 

// TODO: Try the recursive method



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        vector<int>::iterator it = find(flowerbed.begin(), flowerbed.end(), 1);
        int index = 0;
        int max = 0; 
        if (it != flowerbed.end()){
            index = (it - flowerbed.begin());
            // if (index%2 == 0){
                for (int i = 0; i < size; ){
                    bool pre = false;
                    bool post =false;
                    if (i > 0){
                        if (flowerbed[i-1] == 0 && flowerbed[i] != 1){
                           pre = true;
                        }
                    }
                    else if(i == 0){
                        if (flowerbed[i] == 0){
                            pre =true;
                        }
                    }
                    if(i < size - 1){
                        if (flowerbed[i+1] == 0 && flowerbed[i] != 1){
                            post = true;
                        }
                    }
                    else if(i == size -1){
                        if (flowerbed[i] == 0){
                            post = true;
                        }
                    }
                    
                    if (pre && post){
                        flowerbed[i] = 1;
                        max +=1;
                    }
                    i += 2;
                }
                
            // }
            // else{
                for (int i = 1; i < size; ){
                    bool pre = false;
                    bool post =false;
                    if (i > 0){
                        if (flowerbed[i-1] == 0 && flowerbed[i] != 1){
                           pre = true;
                        }
                    }
                    else if(i == 0){
                        if (flowerbed[i] == 0){
                            pre =true;
                        }
                    }
                    if(i < size - 1){
                        if (flowerbed[i+1] == 0 && flowerbed[i] != 1){
                            post = true;
                        }
                    }
                    else if(i == size -1){
                        if (flowerbed[i] == 0){
                            post = true;
                        }
                    }
                    // cout << "pre: " << pre << ", post: " << post << endl;
                    if (pre && post){
                        cout << "I: " << i <<endl;
                        max +=1;
                    }
                    i += 2;
                }
                cout << "max " << max << endl;
                return n <= max;
            // }

        }
        else if(size%2 == 0){
            return n <= size/2;
        }
        else{
            return n <= ((size/2) + 1);
        }
        return false;
    }
};