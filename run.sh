if [ -e build ] ; 
    then 
        find build/ -not -name "statistics.txt" -delete
    else 
        mkdir build
fi

cd build

cmake ../src

make

./Fast-Typing