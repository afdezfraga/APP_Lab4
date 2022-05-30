TARGETS=dyn_balance dyn_balance_rdma
MPICC=mpicc

all: $(TARGETS)

$(TARGETS): % : %.c
	$(MPICC) -o $@ $^

clean:
	rm -f $(TARGETS) *.o
