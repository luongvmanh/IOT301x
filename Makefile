.PHONY: clean All

All:
	@echo "----------Building project:[ Bai2_Lab1 - Debug ]----------"
	@cd "Bai2_Lab1" && "$(MAKE)" -f  "Bai2_Lab1.mk"
clean:
	@echo "----------Cleaning project:[ Bai2_Lab1 - Debug ]----------"
	@cd "Bai2_Lab1" && "$(MAKE)" -f  "Bai2_Lab1.mk" clean
