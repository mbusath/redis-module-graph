#include <stdio.h>
#include <string.h>
#include "assert.h"
#include "../src/aggregate/functions.h"
#include "../src/value.h"

int main(int argc, char **argv) {
	
	// Empty node
	AggCtx* sumCtx = Agg_SumFunc();
	double sum = 0;
	SIValue item;
	
	for(int i = 0; i < 10; i++) {
		item = SI_IntVal(i);
    	sumCtx->Step(sumCtx, &item, 1);
		sum += i;
	}

    sumCtx->ReduceNext(sumCtx);
	assert(sumCtx->result.doubleval == sum);
	
	printf("PASS!");
    return 0;
}