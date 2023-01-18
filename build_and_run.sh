if [ -e build ] ; 
    then 
        rm -r build/*
    else 
        mkdir build
fi

cd build

cmake ../src

make

./Fast-Typing-Training


