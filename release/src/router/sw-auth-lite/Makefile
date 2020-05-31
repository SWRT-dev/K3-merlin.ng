include ../common.mak

AUTHLIB=libsw_auth.so
TOOL=sw_auth

CFLAGS  += -Werror -fPIC -I.
CFLAGS	+= -I$(TOP)/shared -I$(SRCBASE)/include -I$(SRCBASE)/common/include
CFLAGS	+= $(if $(WLAN_ComponentIncPath),$(WLAN_ComponentIncPath),$(addprefix -I,$(wildcard $(SRCBASE)/shared/bcmwifi/include)))
CFLAGS	+= -s -O2

# BUILD_NAME
ifneq ($(findstring 4G-,$(BUILD_NAME)),)
TARGET_MODEL = RT$(subst -,,$(BUILD_NAME))
else ifneq ($(findstring DSL,$(BUILD_NAME)),)
TARGET_MODEL = $(subst -,_,$(BUILD_NAME))
else
TARGET_MODEL = $(subst -,,$(subst +,P,$(BUILD_NAME)))
endif
CFLAGS  += -D$(TARGET_MODEL)
CFLAGS  += -D$(MERLINR_NAME)
CFLAGS += -DMERLINR_VER_MAJOR_$(MERLINR_VER_MAJOR)
CFLAGS  += -I$(TOP)/openssl/include

AUTHLIB_LIBS = -L$(TOP)/openssl -lssl -lcrypto -ldl -lm

LDFLAGS = -L.
LDFLAGS += -L$(TOP)/nvram$(BCMEX)${EX7} ${EXTRA_NV_LDFLAGS} -lnvram
LDFLAGS += -L$(TOP)/shared -L$(INSTALLDIR)/shared/usr/lib -lshared
ifeq ($(HND_ROUTER),y)
LDFLAGS += $(EXTRALDFLAGS)
endif

ifneq ($(wildcard $(SRCBASE)/router/sw-auth-lite/*.c),)
OBJS = main.o
LIBOBJS = sw_auth.o
all : $(AUTHLIB)
else
all :
	cp -f prebuild/$(AUTHLIB) ./
endif

$(AUTHLIB): $(LIBOBJS)
	@echo "[sw-auth-lite] $(AUTHLIB)"
	@$(CC) $(LIBOBJS) -shared -o $(AUTHLIB) $(CFLAGS) $(LDFLAGS) $(AUTHLIB_LIBS)

$(TOOL) : $(OBJS)
	@echo "[sw-auth-lite] $(TOOL)"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(AUTHLIB_LIBS) -o $@ $^

install: all
	@echo "[sw-auth-lite] Installing..."
	-@install -d $(INSTALLDIR)/usr/sbin
	-@install -d $(INSTALLDIR)/usr/lib
	#-@install -m 755 $(TOOL) $(INSTALLDIR)/usr/sbin
	-@install -m 755 $(AUTHLIB) $(INSTALLDIR)/usr/lib

clean:
	rm -f *.o *.so $(TARGET) $(TOOL)
