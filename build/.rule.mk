$(BUILD_DIR)/$(PROJ_NAME): $(C_OBJS) $(CXX_OBJS)
	@echo Linking $@
	@$(CXX) $^ $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@echo Gen $@
	@mkdir -p $(dir $@)
	@echo $(sort $(CFLAGS)) > $(basename $@)_CFLAGS
	@$(CC) @$(basename $@)_CFLAGS -MMD -MF $(basename $@).d -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo Gen $@
	@mkdir -p $(dir $@)
	@echo $(sort $(CXXFLAGS)) > $(basename $@)_CXXFLAGS
	@$(CXX) @$(basename $@)_CXXFLAGS -MMD -MF $(basename $@).d -c $< -o $@
