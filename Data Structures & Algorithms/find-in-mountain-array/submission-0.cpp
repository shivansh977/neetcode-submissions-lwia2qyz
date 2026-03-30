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
private:
    int findPeakId(MountainArray &arr){
        int l=0;
        int r=arr.length()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=arr.get(mid);
            bool inc1=true;
            bool inc2=false;
            if(mid>0&&arr.get(mid)<arr.get(mid-1)) inc1=false;
            if(mid+1<arr.length()&&arr.get(mid+1)>arr.get(mid)) inc2=true;
            if(inc1&&inc2){
                l=mid+1;
            }
            else if(!inc1&&!inc2){
                r=mid-1;
            }
            else if(inc1&&!inc2){
                return mid;
            }
        }
        return -1;
    }
    int findVal(MountainArray &arr, int st, int en, bool inc, int target){
        while(st<=en){
            int mid=st+(en-st)/2;
            int val=arr.get(mid);
            if((arr.get(mid)>target&&inc)||(arr.get(mid)<target&&!inc)){
                en=mid-1;
            }
            else if((arr.get(mid)<target&&inc)||(arr.get(mid)>target&&!inc)){
                st=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakId = findPeakId(mountainArr);
        int id1=findVal(mountainArr,0,peakId,true,target);
        int id2=findVal(mountainArr,peakId+1,mountainArr.length()-1,false,target);
        if(id1==-1&&id2==-1){
            return -1;
        }
        else if(id1==-1){
            return id2;
        }
        return id1;
    }
};