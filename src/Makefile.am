AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = -Wall -std=c++11 -DFORTIFY_SOURCE=2 -DGCRYPT_NO_DEPRECATED
AM_LDFLAGS = -Wl,-rpath=/lib/homegear -Wl,-rpath=/usr/lib/homegear -Wl,-rpath=/usr/local/lib/homegear
LIBS += -Wl,-Bdynamic,-lserial

libdir = $(localstatedir)/lib/homegear/modules
lib_LTLIBRARIES = mod_somfy.la
mod_somfy_la_SOURCES = MyFamily.cpp MyFamily.h MyPacket.cpp MyPacket.h MyPeer.cpp MyPeer.h Factory.cpp Factory.h GD.cpp GD.h MyCentral.cpp MyCentral.h Interfaces.h Interfaces.cpp PhysicalInterfaces/ISomfyInterface.h PhysicalInterfaces/ISomfyInterface.cpp PhysicalInterfaces/Cunx.h PhysicalInterfaces/Cunx.cpp PhysicalInterfaces/Cul.h PhysicalInterfaces/Cul.cpp
mod_somfy_la_LDFLAGS =-module -avoid-version -shared
install-exec-hook:
	rm -f $(DESTDIR)$(libdir)/mod_somfy.la
