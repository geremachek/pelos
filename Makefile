TARGET = pelos

pelos:
	gcc -ansi main.c linear_b.c -o $(TARGET)

clean:
	$(RM) $(TARGET)

test:
	./$(TARGET) < test.txt
