int numWaterBottles(int numBottles, int numExchange){
    int changed = numBottles;
    int num = numBottles;
    int count = numBottles;
    int temp;
    while (true) {
        if(changed == 0)
            break;
        changed = num / numExchange;
        temp = num % numExchange;
        num = changed +temp;
        count += changed;

    }
    return count;
    

}

