const char HTTP_HEAD[]             PROGMEM = "<!DOCTYPE html><html lang='en'><head><meta name='format-detection' content='telephone=no'><meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/><title>{v}</title>";
const char HTTP_SCRIPT[]           PROGMEM = "<script>function c(l){document.getElementById('s').value=l.innerText||l.textContent;document.getElementById('p').focus();}</script>";
const char HTTP_HEAD_END[]         PROGMEM = "</head><body><div class='wrap'>";
const char HTTP_PORTAL_OPTIONS[]   PROGMEM = "<form action='/wifi' method='GET'><button>Configure WiFi</button></form><br/><form action='/0wifi' method='GET'><button>Configure WiFi (No Scan)</button></form><br/><form action='/i' method='GET'><button>Info</button></form><br/><form action='/r' method='GET'><button>Restart</button></form><br/><form action='/exit' method='GET'><button>Quit</button></form>";
const char HTTP_ITEM[]             PROGMEM = "<div><a href='#p' onclick='c(this)'>{v}</a><div role='img' aria-label='{r}%' title='{r}%' class='q q-{q} {i}'></div></div>";
// const char HTTP_ITEM[]            PROGMEM = "<div><a href='#p' onclick='c(this)'>{v}</a> {R} {r}% {q} {e}</div>"; // test all tokens
const char HTTP_FORM_START[]       PROGMEM = "<form method='POST' action='wifisave'><label for='s'>SSID</label><input id='s' name='s' maxlength=32 placeholder='{v}'><br/><label for='p'>Password</label><input id='p' name='p' maxlength='64' type='password' placeholder=''><br/>";
const char HTTP_FORM_END[]         PROGMEM = "<br/><button type='submit'>Save</button></form>";
const char HTTP_FORM_LABEL[]       PROGMEM = "<label for='{i}'>{t}</label>";
const char HTTP_FORM_PARAM_START[] PROGMEM = "<hr>";
const char HTTP_FORM_PARAM[]       PROGMEM = "<br/><input id='{i}' name='{n}' maxlength={l} placeholder='' value='{v}' {c}>";
const char HTTP_FORM_PARAM_END[]   PROGMEM = "<br/>";
const char HTTP_SCAN_LINK[]        PROGMEM = "<br/><form action='/wifi' method='get'><button>Refresh</button></form>";
const char HTTP_SAVED[]            PROGMEM = "<div class='msg'>Saving Credentials<br/>Trying to connect ESP to network.<br />If it fails reconnect to AP to try again</div>";
const char HTTP_END[]              PROGMEM = "</div></body></html>";

const char HTTP_STYLE[]            PROGMEM = "<style>"
".c,body{text-align:center;font-family:verdana}div,input{padding:5px;font-size:1em}input{width:95%;margin:5px 0}button{cursor:pointer;border:0;border-radius:.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%}"
".wrap {text-align:left;display:inline-block;min-width:260px}"
// links
"a{color:#000;font-weight:700;text-decoration:none}a:hover{color:#1fa3ec;text-decoration:underline}"
// quality icons
".q{height:16px;margin:0;padding:0 5px;text-align:right;min-width:38px;float:right}.q.q-0:after{background-position-x:0}.q.q-1:after{background-position-x:-16px}.q.q-2:after{background-position-x:-32px}.q.q-3:after{background-position-x:-48px}.q.q-4:after{background-position-x:-64px}.q.l:before{background-position-x:-80px;padding-right:5px}.ql .q{float:left}.qinv .q{-webkit-filter:invert(1);filter:invert(1)}.q:after,.q:before{content:'';width:16px;height:16px;display:inline-block;background-repeat:no-repeat;background-position: 16px 0;"
"background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGAAAAAQCAMAAADeZIrLAAAAJFBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADHJj5lAAAAC3RSTlMAIjN3iJmqu8zd7vF8pzcAAABsSURBVHja7Y1BCsAwCASNSVo3/v+/BUEiXnIoXkoX5jAQMxTHzK9cVSnvDxwD8bFx8PhZ9q8FmghXBhqA1faxk92PsxvRc2CCCFdhQCbRkLoAQ3q/wWUBqG35ZxtVzW4Ed6LngPyBU2CobdIDQ5oPWI5nCUwAAAAASUVORK5CYII=');}"
// icons @2x media query (32px rescaled)
"@media (-webkit-min-device-pixel-ratio: 2),(min-resolution: 192dpi){.q:before,.q:after {"
"background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAALwAAAAgCAMAAACfM+KhAAAALVBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADAOrOgAAAADnRSTlMAESIzRGZ3iJmqu8zd7gKjCLQAAACmSURBVHgB7dDBCoMwEEXRmKlVY3L//3NLhyzqIqSUggy8uxnhCR5Mo8xLt+14aZ7wwgsvvPA/ofv9+44334UXXngvb6XsFhO/VoC2RsSv9J7x8BnYLW+AjT56ud/uePMdb7IP8Bsc/e7h8Cfk912ghsNXWPpDC4hvN+D1560A1QPORyh84VKLjjdvfPFm++i9EWq0348XXnjhhT+4dIbCW+WjZim9AKk4UZMnnCEuAAAAAElFTkSuQmCC');"
"background-size: 95px 16px;}}"
// msg callouts
".msg{padding:20px;margin:20px 0;border:1px solid #eee;border-left-width:5px;border-radius:3px;border-left-color:#777}.msg h4{margin-top:0;margin-bottom:5px}.msg.P{border-left-color:#1fa3ec}.msg.P h4{color:#1fa3ec}.msg.D{border-left-color:#d9534f}.msg.D h4{color:#d9534f}"
// lists
"dt{font-weight:bold}dd{margin:0;padding:0 0 0.5em 0}"
"</style>";

const char HTTP_HELP[]             PROGMEM =
 "<br/><h3>Available Pages</h3><hr>"
 "<table class='table'>"
 "<thead><tr><th>Page</th><th>Function</th></tr></thead><tbody>"
 "<tr><td><a href='/'>/</a></td>"
 "<td>Menu page.</td></tr>"
 "<tr><td><a href='/wifi'>/wifi</a></td>"
 "<td>Show WiFi scan results and enter WiFi configuration.(/0wifi noscan)</td></tr>"
 "<tr><td><a href='/wifisave'>/wifisave</a></td>"
 "<td>Save WiFi configuration information and configure device. Needs variables supplied.</td></tr>"
 "<tr><td><a href='/close'>/close</a></td>"
 "<td>Close the configuration server and configuration WiFi network.</td></tr>"
 "<tr><td><a href='/i'>/i</a></td>"
 "<td>Information page</td></tr>"
 "<tr><td><a href='/exit'>/exit</a></td>"
 "<td>Exit Config Portal, configportal will close</td></tr>"
 "<tr><td><a href='/r'>/r</a></td>"
 "<td>Reboot the device</td></tr>"
 "<tr><td><a href='/erase'>/erase</a></td>"
 "<td>Erase WiFi configuration and reboot Device. Device will not reconnect to a network until new WiFi configuration data is entered.</td></tr>"
 "</table>"
 "<p/>More information about WiFiManager at <a href='https://github.com/tzapu/WiFiManager'>https://github.com/tzapu/WiFiManager</a>.";