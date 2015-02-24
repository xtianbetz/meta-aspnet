SRC_URI="https://www.nuget.org/api/v2/package/KRE-Mono/${PV};downloadfilename=XRE-Mono.${PV}.zip;name=kre;subdir=kre-bin-${PV} \
         https://raw.githubusercontent.com/aspnet/XRE/dev/LICENSE.txt;name=license;downloadfilename=XRE-license"
LICENSE="Apache-2.0"			
LIC_FILES_CHKSUM="file://${WORKDIR}/XRE-license;md5=18d62531c894e91f9f01b5146b73468d"
RDEPENDS_${PN}+="mono"
BBCLASSEXTEND=+"native"

SRC_URI[license.md5sum] = "18d62531c894e91f9f01b5146b73468d"
SRC_URI[license.sha256sum] = "3b8b4437035351a81b3b808172c5c4133eafd86480ee41a67a080ee973dc3897"

S="${WORKDIR}/kre-bin-${PV}"

do_install() {
    install -d ${D}${bindir}
    for i in k kpm; do
        target=${D}${bindir}/${i}
        # Update the scripts to look in libdir
        sed -e "2,9d" -e "10iDIR=${libdir}/${PN}" ${S}/bin/${i} > ${target}
        chmod 0755 ${target}
    done

    install -d ${D}${libdir}/${PN}/lib

    target=${D}${libdir}/${PN}/klr
    sed -e "2,9d" -e "10iDIR=${libdir}/${PN}" ${S}/bin/klr > ${target}
    chmod 0755 ${target}

    for i in ${S}/bin/*.dll; do
        install $i ${D}${libdir}/${PN}
    done
    
    for i in ${S}/bin/lib/*; do
        dirname=$(basename "$i")
        install -d ${D}${libdir}/${PN}/lib/${dirname}
        for j in ${S}/bin/lib/${dirname}/*.dll; do
            install $j ${D}${libdir}/${PN}/lib/${dirname}
        done
    done
}