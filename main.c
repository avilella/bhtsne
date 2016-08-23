#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t-sne.h"

int main(int argc, char *argv[])
{
	int c, seed = 11, out_dim = 2, N, n_in, i, j;
	double perplexity = 50., theta = .5, *x, *y;
	char **row_names;

	while ((c = getopt(argc, argv, "s:p:e:d:")) >= 0) {
		if (c == 's') seed = atoi(optarg);
		else if (c == 'p') perplexity = atof(optarg);
		else if (c == 'e') theta = atof(optarg);
		else if (c == 'd') out_dim = atoi(optarg);
	}

	if (argc == optind) {
		fprintf(stderr, "Usage: t-sne [options] <in.snd>\n");
		fprintf(stderr, "Options:\n");
		fprintf(stderr, "  -d INT      output dimension [%d]\n", out_dim);
		fprintf(stderr, "  -e FLOAT    step size (theta) [%g]\n", theta);
		fprintf(stderr, "  -p FLOAT    perplexity [%g]\n", perplexity);
		fprintf(stderr, "  -s INT      random seed [%d]\n", seed);
		return 1;
	}

	x = sann_data_read_1d(argv[optind], &N, &n_in, &row_names, 0);
	y = ts_fit(N, n_in, x, out_dim, theta, perplexity, seed);
	for (i = 0; i < N; ++i) {
		int k = i * out_dim;
		printf("%s", row_names[i]);
		for (j = 0; j < out_dim; ++j)
			printf("\t%g", y[k+j] + 1. - 1.);
		putchar('\n');
	}
	free(y);
	return 0;
}
