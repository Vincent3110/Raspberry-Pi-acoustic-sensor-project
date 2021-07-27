<?php
$log_file = 'sound_log.txt';		//log file name
$data = $_POST['data'];
date_default_timezone_set("UTC");
$str = gmdate("M d Y H:i:s", time()).', '.$data."\n";		//two feild in one record, the time stamp and point data
//echo "This is from the server";
//now open the file
if(file_exists($log_file))
{
	$fp = fopen($log_file, "a");	
	fwrite($fp, $str);
	fclose($fp);
}
else
{
	$fp = fopen($log_file, "w");	
	fwrite($fp, $str);
	fclose($fp);
}
echo "Data is stored\n";	//echo sth back to raspberry
?>