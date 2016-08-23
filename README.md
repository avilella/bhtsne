## Getting Started
```sh
git clone https://github.com/lh3/bhtsne
cd bhtsne
make
./t-sne brain8.snd.gz > reduced.snd          # dimension reduction
perl -pe 's/:[^\s]+//' reduced.snd > in.txt  # extract colors from row names
echo 'plot "in.txt" u 2:3:1 not lc var;pause 10'|gnuplot  # requiring gnuplot
```

## Introduction

This is a fork of [Laurens van der Maaten][maaten]'s implementation of the
[t-SNE algorithm][tsne]. It adds a C interface to the original code and
provides a more convenient command-line interface. The command-line tool now
takes the SND format as input, where each data line consists of a sample name
and a vector for the sample.

[tsne]: http://lvdmaaten.github.io/tsne/
[maaten]: https://lvdmaaten.github.io/
