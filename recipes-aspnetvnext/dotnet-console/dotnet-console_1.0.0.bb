inherit dotnet

LICENSE="MIT"
SRC_URI="https://raw.githubusercontent.com/dotnet/templating/v3.1.4/LICENSE;downloadfilename=LICENSE-dotnetconsoletemplate"
LIC_FILES_CHKSUM="file://LICENSE-dotnetconsoletemplate;md5=9b9b77eef35c4b2667bfd2f93f3d602f"
SRC_URI[md5sum] = "9b9b77eef35c4b2667bfd2f93f3d602f"
SRC_URI[sha256sum] = "25626de6ac49462ee7ce16f453746729889615bf5efb9d0b705ae645bd792eff"

S="${WORKDIR}/${PN}"
# RID_PARAMETER = ""

TARGET_FRAMEWORK = "netcoreapp3.1"

do_unpack () {
	mkdir -p ${WORKDIR}/${PN}
	cp ${DL_DIR}/LICENSE-dotnetconsoletemplate ${WORKDIR}/${PN}
	cd ${WORKDIR}/${PN}
	dotnet new console
}

