check:
	cd test/doc && ./test.py
	pep8 --ignore=E501 doc-dump.py msodumper/doc{dirstream,record,sprm,stream}.py test/doc/test.py
	pep8 --ignore=E501 emf-dump.py msodumper/{emf,wmf}record.py
