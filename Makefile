CC=		g++

OBJS=		$(OUT_PATH)/strtokenizer.o $(OUT_PATH)/dataset.o $(OUT_PATH)/utils.o $(OUT_PATH)/model.o
MAIN=		lda
SRC_PATH=   src
OUT_PATH=   out

all:	$(OBJS) $(SRC_PATH)/$(MAIN).cpp
	$(CC) -o $(OUT_PATH)/$(MAIN) $(SRC_PATH)/$(MAIN).cpp $(OBJS)
	strip $(OUT_PATH)/$(MAIN)

$(OUT_PATH)/strtokenizer.o:	$(SRC_PATH)/strtokenizer.h $(SRC_PATH)/strtokenizer.cpp
	$(CC) -c -o $(OUT_PATH)/strtokenizer.o $(SRC_PATH)/strtokenizer.cpp

$(OUT_PATH)/dataset.o:	$(SRC_PATH)/dataset.h $(SRC_PATH)/dataset.cpp
	$(CC) -c -o $(OUT_PATH)/dataset.o $(SRC_PATH)/dataset.cpp

$(OUT_PATH)/utils.o:	$(SRC_PATH)/utils.h $(SRC_PATH)/utils.cpp
	$(CC) -c -o $(OUT_PATH)/utils.o $(SRC_PATH)/utils.cpp

$(OUT_PATH)/model.o:	$(SRC_PATH)/model.h $(SRC_PATH)/model.cpp
	$(CC) -c -o $(OUT_PATH)/model.o $(SRC_PATH)/model.cpp

test:
	

clean:
	rm $(OBJS) 
	rm $(OUT_PATH)/$(MAIN)

