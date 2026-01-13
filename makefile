SUBDIRS = src test/int/ test/simple_precision/ test/double_precision/


.PHONY: subdirs $(SUBDIRS) clean bench

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

test/int test/simple_precision test/double_precision: src

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
		done

bench:
	$(MAKE) -C test/int bench &
	$(MAKE) -C test/simple_precision bench &
	$(MAKE) -C test/double_precision bench &
	wait

