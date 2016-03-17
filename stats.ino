// code for averaging an array
// stats array format (mean, std_dev, min, max, median)

float stats(int arr[], int reps, float statss[]) {


  // calculate mean of the array
  long sum = 0; //must be long bc sum of int will easily roll over
  for (int i = 0; i < reps; i++) {
    sum = sum + arr[i];
  }
  statss[0] = sum / reps; //mean

  //calculate std dev of the array
  long dif2 = 0; //long to prevent roll over
  for (int i = 0; i < reps; i++) {
    dif2 = dif2 + (sq(arr[i] - statss[0]));
  }

  statss[1] = sqrt(dif2 / reps); //std_dev


  //calculate min, max and median ofthe array


  for (int i = 0; i < (reps - 1); i++) {
    for (int o = 0; o < (reps - (i + 1)); o++) {
      if (arr[o] > arr[o + 1]) {
        int t = arr[o];
        arr[o] = arr[o + 1];
        arr[o + 1] = t;
      }
    }
  }

statss[2] = arr[0]; //min
statss[3] = arr[49]; //max
statss[4]=(arr[24]+arr[25])/2;  //median for an even sample size
  
}  //end function




//reference for sorting algorithim

/*
  void sort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] > a[o+1]) {
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
                }
        }
    }
  }
*/
