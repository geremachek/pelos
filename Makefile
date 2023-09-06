TARGET = pelos

pelos:
	gcc -Wall -ansi main.c signs.c -o $(TARGET)

debug:
	gcc -ansi -g -fsanitize=address main.c linear_b.c -o $(TARGET)

clean:
	$(RM) $(TARGET)

test-lb:
	./$(TARGET) -l < test.lb.txt

test-cy:
	./$(TARGET) -c < test.cy.txt
