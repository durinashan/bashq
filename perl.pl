sub store($globpattern, $thedata) {
open($fnames, "ls -t ".$globpattern . " | head -n 1 |") ||
die "Can not glob";
$filename = <$fnames>;
close($fnames);
chomp($filename);
if (-l $filename) {
die "Not writing to symlink!"
}
open ($fh, ">", $filename) || die "Can not open file";
print $fh $thedata;
close $fh;
}
