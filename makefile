SUBDIRS = src test/int/ test/simple_precision/ test/double_precision/

.PHONY: subdirs $(SUBDIRS) clean

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

test/int test/simple_precision test/double_precision: src

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
		done
