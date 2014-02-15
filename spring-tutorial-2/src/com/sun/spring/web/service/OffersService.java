package com.sun.spring.web.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sun.spring.web.dao.Offer;
import com.sun.spring.web.dao.OfferDao;

@Service("offersService")
public class OffersService {
	
	private OfferDao offersDao;

	@Autowired
	public void setOffersDao(OfferDao offersDao) {
		this.offersDao = offersDao;
	}

	public List<Offer> getCurrent() {
		return offersDao.getOffers();
	}
}
