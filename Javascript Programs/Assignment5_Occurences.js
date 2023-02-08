var arr=new Object();
    function checkOccurence(num) {
        let i, rem = 1;
        
         for (i = 0; i <= 9; i++) {
             arr[i] = 0;
         }
        
        while (Math.trunc(num) != 0) {
            rem = num % 10;
            arr[rem] = arr[rem] + 1;
            num = Math.trunc(num / 10);
        }

        return arr;
    }
    var arr1=[];
    arr1=checkOccurence(123);
    console.log(arr1);