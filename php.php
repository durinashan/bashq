<?php
$sql="SELECT name,location FROM loc WHERE ID=".
addslashes($_REQUEST[’id’]);
$result = mysql_query($cmd) || die($cmd);
while($row = mysql_fetch_array($result)) {
echo $row[’name’] . ", " . row[’location’] . "<br>";
}
$fn = escapeshellcmd($_REQUEST[’user’]);
$file = fopen("/var/www/avatars/".$fn, "r");
fpassthru($file);
fclose($file);
echo "You are using " . $_SERVER[’HTTP_USER_AGENT’] . "\n\n";
?>
