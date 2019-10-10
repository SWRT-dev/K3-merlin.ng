<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<html xmlns:v>
<head>
<meta http-equiv="X-UA-Compatible" content="IE=Edge"/>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta HTTP-EQUIV="Pragma" CONTENT="no-cache">
<meta HTTP-EQUIV="Expires" CONTENT="-1">
<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
<link rel="icon" href="images/favicon.png">
<title><#Web_Title#></title>
<style>
@font-face{
	font-family: ROG;
	src: url(/fonts/ROG_Fonts-Regular.woff) format("woff"),
	     url(/fonts/ROG_Fonts-Regular.otf) format("opentype");
}
body, .p1, .form-input{
	color: #FFF;
}
body{
	font-family: Roboto, Arial, STHeiti, Microsoft JhengHei, sans-serif;
	background-color: rgb(31, 31, 31) !important;
}
.bg{
	background: url(/images/New_ui/login_bg.png) no-repeat center center fixed;
	-webkit-background-size: cover;
	-moz-background-size: cover;
	-o-background-size: cover;
	background-size: cover;
	background:#283437\9;
}
.logo-container{
	display: flex;
	align-items: center;
	margin-left: 150px;
}
.logo-container-odm{
	display: flex;
	justify-content: space-between;
}
.main-field-bg{
	margin:20px auto 0;
	width: 887px;
	height: 849px;
}
.main-field-bg-odm{
	margin:20px auto 0;
	width: 1180px;
	height: 849px;
	background: url('./images/New_ui/COD_rog_bg_login.png') no-repeat;
}
.main-field-padding{
	width: 887px;
	margin: 0 auto;	
}
.logo-rog{
	background:url('./images/New_ui/ROG-logo.png') no-repeat;
}
.logo-odm{
	background:url('./images/New_ui/COD_logo.png') no-repeat;
}
.logo-rog, .logo-odm{
	width: 290px;
	height: 191px;
}
.model-name{
	width: 420px;
	height: 100%;
	font-size: 48px;
	font-weight: bold;
	font-family: ROG;
	margin-left: 25px;
}
.login-bg, .login-bg-odm{
	width: 887px;
	height: 600px;
}
.login-bg-odm{
	background: url('./images/New_ui/ROG-Sec_login.png') no-repeat;
}
..login-field-padding{
	padding-top: 0;
}
.login-field-padding-odm{
	padding-top: 60px;
}
.login-title{
	width: 350px;
	height: 73px;
	margin: 0 auto;
	text-align: center;
	line-height: 73px;
	font-size: 32px;
	background: url('./images/New_ui/ROG-Sec_titleName.png') no-repeat;
}
.login-title-desc{
	text-align: center;
	font-size: 16pt;
	margin: 15px auto;
}
.input-container{
	display: flex;
	justify-content: center;
	margin: 0 0 20px 0;
}
.error-hint-bg{
	width: 537px;
	height: 70px;
	display:flex;
	align-items: center;
	margin: 40px auto;
	background: url('./images/New_ui/icon_Sec_hint.png') no-repeat;
}
.error-text{
	margin: 0 30px 0 112px;
	font-size: 20px;
}
.login-btn-bg{
	width: 250px;
	height: 60px;
	line-height: 60px;
	border: 2px solid #842500;
	float: right;
	margin: 20px 230px 0 0;
	background: #141618;
	border-radius: 8px;
}
.login-btn-bg:hover{
	border: 2px solid #AB0015;
}
.login-btn-bg-odm{
	width: 404px;
	height: 66px;
	line-height: 58px;
	margin: 35px auto 15px auto;
	background: url('./images/New_ui/btn_signIn.png') no-repeat;
}
.login-btn-bg, .login-btn-bg-odm{
	text-align: center;
	font-size: 28px;
	cursor: pointer;
}
.nologin-container{
	margin-left: 112px;
	font-size: 22px;
}
.nologin-text{
	padding-bottom: 5px;
}
.logout-text{
	margin: 0 30px 0 112px;
	font-size: 22px;
}
.error-text, 
.nologin-container, 
.logout-text, 
.error_hint,
.login-btn-bg-odm:hover{
	color: #45FFF0;
}
.p1{
	font-size: 16pt;
	width: 480px;
	margin: 10px 0 5px 240px;
}
.form-input{
	width: 380px;
	height: 30px;
	font-size: 28px;
	padding: 18px 22px;
	border: none;
	outline: none;
	border-bottom: 2px solid rgb(112, 0, 14);
	border-radius: 4px;
	background-color: rgba(0,0,0,0.5);
	background-color: #576D73\9;
}
.form-input:focus{
	border-bottom: 2px solid #AB0015;
}
/*for mobile device*/
@media screen and (max-width: 1000px){
.main-field-bg, .main-field-bg-odm{
	width: 100%;
	margin: 0;
	background-size: 200%;
	background-position: 50% 20%;
}
.main-field-padding{
	width: 100%;
}
.logo-container{
	margin-left: 0;
}
.logo-rog{
	margin: 0 auto;
}
.logo-odm{
	display:none;
}
.model-name{
	display: none;
}
.login-bg, .login-bg-odm{
	width: 100%;
	background: url("");
}
.login-title{
	display: none;
}
.login-field-padding{
	padding: 0;
}
.login-field-padding-odm{
	padding: 10px 0 0 0; 
}
.login-btn-bg, .login-btn-bg-odm{
	width: 95%;
	background-size: 100%;
}
.login-btn-bg{
	line-height: 58px;
}
.login-btn-bg-odm{
	line-height: 52px;
}
.login-btn-bg, .input-container{
	margin: 0 10px 20px 10px;
}
.error-hint-bg{
	width: 100%;
	height: 52px;
	background-size: 100%;
}
.error-text{
	line-height: 20px;
}
.error-text, .nologin-container{
	margin: 0 10px 0 90px ;
}
.form-input{	
	padding:10px 11px;
	width: 100%;
	font-size: 16px
}
.p1{
	font-size: 12pt;
	width:100%;
	margin: 0 0 5px 10px;
}


}
</style>
<script>
var odm_support = ('<% nvram_get("rc_support"); %>'.indexOf('odm') != -1) ? true : false;

/* add Array.prototype.forEach() in IE8 */
if(typeof Array.prototype.forEach != 'function'){
	Array.prototype.forEach = function(callback){
		for(var i = 0; i < this.length; i++){
			callback.apply(this, [this[i], i, this]);
		}
	};
}

function tryParseJSON (jsonString){
    try {
        var o = JSON.parse(jsonString);

        if (o && typeof o === "object") {
            return o;
        }
    }
    catch (e) { }

    return false;
};

var login_info =  tryParseJSON('<% login_error_info(); %>');
var isIE8 = navigator.userAgent.search("MSIE 8") > -1; 
var isIE9 = navigator.userAgent.search("MSIE 9") > -1; 
var remaining_time = login_info.lock_time;
var countdownid, rtime_obj;
var redirect_page = login_info.page;
var cloud_file = '<% get_parameter("file"); %>';
var isRouterMode = ('<% nvram_get("sw_mode"); %>' == '1') ? true : false;

var header_info = [<% get_header_info(); %>][0];
var ROUTERHOSTNAME = '<% nvram_get("local_domain"); %>';
var domainNameUrl = header_info.protocol+"://"+ROUTERHOSTNAME+":"+header_info.port;
var chdom = function(){window.location.href=domainNameUrl};
(function(){
	if(ROUTERHOSTNAME !== header_info.host && ROUTERHOSTNAME != "" && isRouterMode){
		setTimeout(function(){
			var s=document.createElement("script");s.type="text/javascript";s.src=domainNameUrl+"/chdom.json?hostname="+header_info.host;var h=document.getElementsByTagName("script")[0];h.parentNode.insertBefore(s,h);
		}, 1);
	}
})();

<% login_state_hook(); %>

function initial(){
	/*handle sysdep for ROG or ODM product*/
	if(odm_support){
		document.getElementsByClassName("main-field-bg")[0].className = "main-field-bg-odm";
		document.getElementsByClassName("logo-container")[0].className = "logo-container-odm";
		document.getElementsByClassName("model-name")[0].className = "logo-odm";
		document.getElementsByClassName("login-bg")[0].className = "login-bg-odm";
		document.getElementsByClassName("login-btn-bg")[0].className = "login-btn-bg-odm";
		document.getElementsByClassName("login-title")[0].style.display = "block";
		document.getElementsByClassName("login-field-padding")[0].className = "login-field-padding-odm";
	}
	else{
		document.getElementsByClassName("model-name")[0].innerHTML = "<#Web_Title2#>"
	}
	
	var flag = login_info.error_status;
	if(isIE8 || isIE9){
		document.getElementById("name_title_ie").style.display ="";
		document.getElementById("password_title_ie").style.display ="";
	}

	if(flag != ""){
		document.getElementById("error_status_field").style.display ="";
		if(flag == 3){
			document.getElementById("error_status_field").innerHTML ="<div class='error-text'>* <#JS_validLogin#></div>";
		}
		else if(flag == 7){
			document.getElementById("error_status_field").innerHTML ="<div class='error-text'>You have entered an incorrect username or password 5 times. Please try again after "+"<span id='rtime'></span>"+" seconds.</div>";
	
			disable_input(1);
			disable_button(1);
			rtime_obj=document.getElementById("rtime");
			rtime_obj.innerHTML=remaining_time;
			countdownid = window.setInterval(countdownfunc,1000);
		}
		else if(flag == 8){
			document.getElementById("login_filed").style.display ="none";
			document.getElementById("hint_field").style.display ="";
			var element = document.createElement('div');
			element.className = 'logout-text';
			element.innerHTML = '<#logoutmessage#>';
			document.getElementById('hint_field').appendChild(element);
		}
		else if(flag == 9){
			var loginUserIp = (function(){
				return (typeof login_ip_str === "function") ? login_ip_str().replace("0.0.0.0", "") : "";
			})();

			var getLoginUser = function(){
				if(loginUserIp === "") return "";

				var dhcpLeaseInfo = [];
				var hostName = "";

				dhcpLeaseInfo.forEach(function(elem){
				if(elem[0] === loginUserIp){
					hostName = " (" + elem[1] + ")";
					return false;
					}
				})

				return "<div>* <#login_hint1#> " + loginUserIp + hostName + "</div>";
			};

			document.getElementById("login_filed").style.display ="none";
			document.getElementById("hint_field").style.display ="";

			var element = document.createElement('div');
			element.setAttribute('class', 'nologin-container');
			var _child_element = document.createElement('div');
			_child_element.setAttribute('class', 'nologin-text');
			_child_element.innerHTML = '<#login_hint2#>';
			element.appendChild(_child_element);

			_child_element = document.createElement('div');
			_child_element.setAttribute('id', 'logined_ip_str');
			element.appendChild(_child_element);
			document.getElementById('hint_field').appendChild(element);
			document.getElementById("logined_ip_str").innerHTML = getLoginUser();
		}
		else{
			document.getElementById("error_status_field").style.display ="none";
		}
	}

	document.form.login_username.focus();

	/*register keyboard event*/
	document.form.login_username.onkeyup = function(e){
		e=e||event;
		if(e.keyCode == 13){
			document.form.login_passwd.focus();
			return false;
		}
	};
	document.form.login_username.onkeypress = function(e){
		e=e||event;
		if(e.keyCode == 13){
			return false;		}
	};

	document.form.login_passwd.onkeyup = function(e){
		e=e||event;
		if(e.keyCode == 13){
			login();
			return false;
		}
	};
	document.form.login_passwd.onkeypress = function(e){
		e=e||event;
		if(e.keyCode == 13){
			return false;
		}
	};

	if(history.pushState != undefined) history.pushState("", document.title, window.location.pathname);
}

function countdownfunc(){ 
	rtime_obj.innerHTML=remaining_time;
	if (remaining_time==0){
		clearInterval(countdownid);
		setTimeout("top.location.href='/Main_Login.asp';", 2000);
	}
	remaining_time--;
}

function login(){

	var trim = function(val){
		val = val+'';
		for (var startIndex=0;startIndex<val.length && val.substring(startIndex,startIndex+1) == ' ';startIndex++);
		for (var endIndex=val.length-1; endIndex>startIndex && val.substring(endIndex,endIndex+1) == ' ';endIndex--);
		return val.substring(startIndex,endIndex+1);
	}

	if(!window.btoa){
		window.btoa = function(input){
			var keyStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
			var output = "";
			var chr1, chr2, chr3, enc1, enc2, enc3, enc4;
			var i = 0;
			var utf8_encode = function(string) {
				string = string.replace(/\r\n/g,"\n");
				var utftext = "";
				for (var n = 0; n < string.length; n++) {
					var c = string.charCodeAt(n);
					if (c < 128) {
						utftext += String.fromCharCode(c);
					}
					else if((c > 127) && (c < 2048)) {
						utftext += String.fromCharCode((c >> 6) | 192);
						utftext += String.fromCharCode((c & 63) | 128);
					}
					else {
						utftext += String.fromCharCode((c >> 12) | 224);
						utftext += String.fromCharCode(((c >> 6) & 63) | 128);
						utftext += String.fromCharCode((c & 63) | 128);
					}
				}
				return utftext;
			};
			input = utf8_encode(input);
			while (i < input.length) {
				chr1 = input.charCodeAt(i++);
				chr2 = input.charCodeAt(i++);
				chr3 = input.charCodeAt(i++);
				enc1 = chr1 >> 2;
				enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
				enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
				enc4 = chr3 & 63;
				if (isNaN(chr2)) {
					enc3 = enc4 = 64;
				}
				else if (isNaN(chr3)) {
					enc4 = 64;
				}
				output = output + 
				keyStr.charAt(enc1) + keyStr.charAt(enc2) + 
				keyStr.charAt(enc3) + keyStr.charAt(enc4);
			}
			return output;
		};
	}

	document.form.login_username.value = trim(document.form.login_username.value);
	document.form.login_authorization.value = btoa(document.form.login_username.value + ':' + document.form.login_passwd.value);
	document.form.login_username.disabled = true;
	document.form.login_passwd.disabled = true;

	try{
		if(redirect_page == "" 
			|| redirect_page == "Logout.asp" 
			|| redirect_page == "Main_Login.asp" 
			|| redirect_page.indexOf(" ") != -1 
			|| redirect_page.indexOf("//") != -1 
			|| redirect_page.indexOf("http") != -1
			|| (redirect_page.indexOf(".asp") == -1 && redirect_page.indexOf(".htm") == -1 && redirect_page != "send_IFTTTPincode.cgi" && redirect_page != "cfg_onboarding.cgi")
		){
			document.form.next_page.value = "";
		}
		else{
			document.form.next_page.value = redirect_page;
		}
	}
	catch(e){
		document.form.next_page.value = "";
	}		

	if(document.form.next_page.value == "cloud_sync.asp"){
		document.form.cloud_file.disabled = false;
		document.form.cloud_file.value = cloud_file;
	}

	document.form.submit();
}

function disable_input(val){
	var disable_input_x = document.getElementsByClassName('form-input');
	for(i=0;i<disable_input_x.length;i++){
		if(val == 0)
			disable_input_x[i].disabled = true;
		else
			disable_input_x[i].style.display = "none";
	}
}

function disable_button(val){
	if(val == 0)
		document.getElementById('button').disabled = true;
	else
		document.getElementById('button').style.display = "none";
}
</script>
</head>
<body onload="initial();" class="bg">
<iframe name="hidden_frame" id="hidden_frame" width="0" height="0" frameborder="0"></iframe>
<iframe id="dmRedirection" width="0" height="0" frameborder="0" scrolling="no" src=""></iframe>
<form method="post" name="form" action="login.cgi" target="">
<input type="hidden" name="group_id" value="">
<input type="hidden" name="action_mode" value="">
<input type="hidden" name="action_script" value="">
<input type="hidden" name="action_wait" value="5">
<input type="hidden" name="current_page" value="Main_Login.asp">
<input type="hidden" name="next_page" value="Main_Login.asp">
<input type="hidden" name="login_authorization" value="">
<input type="hidden" name="cloud_file" value="" disabled>
<div class="main-field-bg">
	<div class="main-field-padding">
		<div class="logo-container">
			<div class="logo-rog"></div>
			<div class="model-name"></div>
		</div>

		<div class="login-bg">
			<div class="login-field-padding">
				<div class="login-title" style="display:none"><#CTL_signin#></div>
				<!-- Login field -->
				<div id="login_filed">
					<div class="login-title-desc"><#Sign_in_title#></div>
					<div id="name_title_ie" style="display:none" class="p1"><#Username#></div>
					<div class="input-container">
						<input type="text" id="login_username" name="login_username" tabindex="1" class="form-input" maxlength="20" autocapitalize="off" autocomplete="off" placeholder="<#Username#>">
					</div>
					<div id="password_title_ie" style="display:none" class="p1"><#HSDPAConfig_Password_itemname#></div>
					<div class="input-container">
						<input type="password" name="login_passwd" tabindex="2" class="form-input" maxlength="16" placeholder="<#HSDPAConfig_Password_itemname#>" autocapitalize="off" autocomplete="off">
					</div>
					<div id="error_status_field" class="error-hint-bg" style="display: none;" ></div>
					<div id="button" class="login-btn-bg" onclick="login();"><#CTL_signin#></div>
				</div>
 
				<!-- Message field --> 
				<div id="hint_field" class="error-hint-bg" style="display: none;"></div>
			</div>
		</div>
	</div>
</div>
</form>
</body>
</html>
