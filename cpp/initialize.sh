problem=${1:-""}
if [ -d $problem ]; then
    echo "$problem exists"
    exit 1
else
    mkdir $problem && cd $problem
    cp ../Makefile .
    python3 ../begin.py >> main.cc
fi

