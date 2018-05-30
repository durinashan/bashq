<?php
if (isset($_REQUEST[’theme’]) {
$file = fopen("/var/www/themes/".$_REQUEST[’theme’], "r");
fpassthru($file);
fclose($file);
$cmd="UPDATE themestats SET hits=hits+1 WHERE theme=’".
$_REQUEST[’theme’]."’");
mysql_query($cmd) || die($cmd);
}
if (isset($_REQUEST[’user’]) {
echo "Welcome, ".$_REQUEST[’user’];
}
?>
