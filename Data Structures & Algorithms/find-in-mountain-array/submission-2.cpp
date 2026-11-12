/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        int peak_idx;

        //Find peak first;
        while(1){
            peak_idx = l + (r - l) / 2;
            int val = mountainArr.get(peak_idx);            
            if(peak_idx != n - 1 && val < mountainArr.get(peak_idx + 1)){
                l = peak_idx + 1;
            }else if(peak_idx != 0 && val < mountainArr.get(peak_idx - 1)){
                r = peak_idx - 1;
            }else{
                if(val == target) return peak_idx;
                break; //find peak
            }
        }

        /*auto binary_search = [&](int begin, int end)->int{
            while(begin <= end){
                int mid = begin + (end - begin) / 2;
                int val = mountainArr.get(mid); 
                if(val == target) return mid;
                else if(val < target) begin = mid + 1;
                else end = mid - 1;
            }
            return -1;
        };*/
       
        int res;
        int begin, end;
        begin = 0, end = peak_idx - 1;
        while(begin <= end){
            int mid = begin + (end - begin) / 2;
            int val = mountainArr.get(mid); 
            if(val == target) return mid;
            else if(val < target) begin = mid + 1;
            else end = mid - 1;
        }

        begin = peak_idx + 1, end = n - 1;
        while(begin <= end){
            int mid = begin + (end - begin) / 2;
            int val = mountainArr.get(mid); 
            if(val == target) return mid;
            else if(val > target) begin = mid + 1;
            else end = mid - 1;
        }

        return -1;        
    }
};