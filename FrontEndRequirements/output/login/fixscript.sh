for f in *.txt; do
	echo $f
	exten=$(echo $f | -d '.' -f)
	if [ ]
	mv -- "$f" "${f%.txt}.out"
done
for f in *.inp; do
	newname=$(echo $f | cut -d '.' -f1)
	echo $newname
	mv -- "$f" "${newname}.out"
done